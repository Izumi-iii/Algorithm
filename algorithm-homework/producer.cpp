#include <iostream>
#include <vector>     // 用于动态大小的缓冲区和锁数组
#include <windows.h>
#include <stdio.h>

// 注意：移除了 using namespace std; 以避免与 <windows.h> 中的 byte 冲突

// --- 全局共享资源和参数 ---
std::vector<bool> g_lock;      // 锁数组：分别对每个缓冲区进行同步
std::vector<int> g_buffer;     // 缓冲区：表示资源的个数
int g_bufferSize = 0;          // 缓冲区数量 (槽位个数)
int g_bufferCapacity = 0;      // 每个缓冲区的最大容量
int g_numProducers = 0;        // 生产者线程数量
int g_numConsumers = 0;        // 消费者线程数量
int g_produceCount = 0;        // 每次生产物资数
int g_consumeCount = 0;        // 每次消费物资数

// --- 显示当前缓冲区状态的函数 ---
void display() {
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "缓冲区数量: " << g_bufferSize << "，容量: " << g_bufferCapacity << std::endl;
    std::cout << "状态: |";
    for (int i = 0; i < g_bufferSize; i++) {
        std::cout << " B" << i << ": " << g_buffer[i] << " |";
    }
    std::cout << "\n------------------------------------" << std::endl;
}

// --- 生产者线程函数 (基于原代码的忙等待/轮询逻辑) ---
DWORD WINAPI Producer(LPVOID lpParameter) {
    int threadID = (int)(intptr_t)lpParameter;

    while (true) {
        int j;

        for (j = 0; j < g_bufferSize; j++) { // 动态循环次数
            if (g_buffer[j] < g_bufferCapacity) {

                // 模拟原代码的 'bool lock' 检查和加锁
                if (g_lock[j] == false) {
                    g_lock[j] = true; // 加锁

                    if (g_buffer[j] < g_bufferCapacity) { // 再次检查

                        for(int k=0; k < g_produceCount; ++k) { // 每次生产 g_produceCount 个物资
                            if (g_buffer[j] < g_bufferCapacity) {
                                ++g_buffer[j]; // 生产资源
                                std::cout << "生产者" << threadID << " 生产" << g_produceCount << "个资源，放入缓冲区" << j << "中" << std::endl;
                            } else {
                                break;
                            }
                        }
                    }

                    g_lock[j] = false; // 解锁

                    if (g_buffer[j] > 0) {
                        break;
                    }
                }
            }
        }

        if (j == g_bufferSize) {
            std::cout << "生产者" << threadID << " 找不到空缓冲区，无法生产，等待中。。" << std::endl;
            Sleep(2000);
        }
    }
    return 0;
}

// --- 消费者线程函数 (基于原代码的忙等待/轮询逻辑) ---
DWORD WINAPI Customer(LPVOID lpParameter) {
    int threadID = (int)(intptr_t)lpParameter;

    while (true) {
        int n;

        for (n = 0; n < g_bufferSize; n++) { // 动态循环次数
            if (g_buffer[n] > 0) {

                // 模拟原代码的 'bool lock' 检查和加锁
                if (g_lock[n] == false) {
                    g_lock[n] = true; // 加锁

                    if (g_buffer[n] > 0) { // 再次检查

                        for (int k = 0; k < g_consumeCount; ++k) { // 每次消费 g_consumeCount 个物资
                            if (g_buffer[n] > 0) {
                                --g_buffer[n]; // 消费资源
                                std::cout << "消费者" << threadID << " 消费" << g_consumeCount << "个资源，从缓冲区" << n << "中取出" << std::endl;
                            } else {
                                break;
                            }
                        }
                    }

                    g_lock[n] = false; // 解锁

                    if (g_buffer[n] < g_bufferCapacity) {
                        break;
                    }
                }
            }
        }

        if (n == g_bufferSize) {
            std::cout << "消费者" << threadID << " 找不到满缓冲区，无法消费，等待中。。" << std::endl;
            Sleep(2000);
        }
    }
    return 0;
}

// --- 主函数 ---
int main(int argc, char* argv[]) {
    // 1. 键盘录入参数
    std::cout << "--- 生产者-消费者模拟参数设置 ---" << std::endl;
    std::cout << "设置缓冲区数量 (槽位个数): ";
    std::cin >> g_bufferSize;
    std::cout << "设置每个槽位的最大容量: ";
    std::cin >> g_bufferCapacity;
    std::cout << "设置生产者数量: ";
    std::cin >> g_numProducers;
    std::cout << "设置消费者数量: ";
    std::cin >> g_numConsumers;
    std::cout << "设置每次生产物资数: ";
    std::cin >> g_produceCount;
    std::cout << "设置每次消耗物资数: ";
    std::cin >> g_consumeCount;

    // 检查输入有效性
    if (g_bufferSize <= 0 || g_bufferCapacity <= 0 || g_numProducers <= 0 || g_numConsumers <= 0) {
        std::cerr << "错误: 所有数量必须大于 0！" << std::endl;
        return 1;
    }

    // 2. 初始化动态缓冲区和锁数组
    g_buffer.resize(g_bufferSize, 0);
    g_lock.resize(g_bufferSize, false);

    display();

    // 3. 动态创建线程
    std::vector<HANDLE> threads;
    DWORD dwThreadID;

    // 创建生产者线程 (使用 1, 2, 3... 作为 ID)
    for (int i = 1; i <= g_numProducers; ++i) {
        HANDLE hThread = CreateThread(NULL, 0, Producer, (LPVOID)(intptr_t)i, 0, &dwThreadID);
        if (hThread) {
            threads.push_back(hThread);
        }
    }

    // 创建消费者线程
    for (int i = 1; i <= g_numConsumers; ++i) {
        // 传递线程ID：使用 i 即可，因为生产者和消费者 ID 空间是独立的
        HANDLE hThread = CreateThread(NULL, 0, Customer, (LPVOID)(intptr_t)i, 0, &dwThreadID);
        if (hThread) {
            threads.push_back(hThread);
        }
    }

    // 4. 主线程休眠一段较长时间
    const int SLEEP_DURATION_MS = 30000;
    std::cout << "\n主线程休眠 " << SLEEP_DURATION_MS / 1000 << " 秒，观察并发执行..." << std::endl;
    Sleep(SLEEP_DURATION_MS);

    // 5. 再次显示缓冲区状态
    display();

    // 6. 清理资源 (在无限循环的线程模型中，只能关闭句柄)
    for (HANDLE h : threads) {
        CloseHandle(h);
    }


    return 0;
}