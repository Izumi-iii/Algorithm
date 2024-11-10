//
// Created by ASUS on 2024/10/30.
//
#include <bits/stdc++.h>
using namespace std;




int main() {
    int n; // 油井数量
    cin >> n;

    vector<double> a(n); // 纵坐标，使用vector动态分配大小

    for (int i = 0; i < n; i++) {
        double x; // 横坐标
        double y; // 纵坐标
        cin >> x >> y; // 输入每个油井的坐标
        a[i] = y; // 将纵坐标存储在vector中
    }
    sort(a.begin(), a.end()); // 对纵坐标进行升序排序

    // 计算各油井到主管道之间的输油管道最小长度总和
    double minLength = 0; // 初始化最小长度
    double median; // 中位数，即主管道的y轴坐标

    if (n % 2 == 0) {
        // 如果油井数量是偶数，中位数是中间两个数的平均值
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    } else {
        // 如果油井数量是奇数，中位数是中间的数
        median = a[n / 2];
    }

    // 计算最小长度总和
    for (int k = 0; k < n; k++) {
        minLength += abs(a[k] - median);
    }

    cout << "主管道的y轴坐标为：" << median << endl;
    cout << "各油井到主管道之间的输油管道最小长度总和为：" << minLength << endl;

    return 0;
}