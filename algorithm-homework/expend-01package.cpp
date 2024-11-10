//
// Created by ASUS on 2024/11/10.
//
#include <bits/stdc++.h>
using namespace std;
// 定义物品的重量数组 w、体积数组 c、价值数组 v，以及三维动态规划数组 dp
int w[99], c[99], v[99], dp[299][299][299];

int main() {
    int n, m, V;
    // 输入背包的重量限制 W、体积限制 V 和物品数量 n
    cin >> m >> V >> n;

    // 输入每个物品的重量、体积和价值
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> v[i];
    }

    // 构建动态规划表
    for (int i = 1; i <= n; i++) {         // 遍历物品
        for (int j = 0; j <= m; j++) {     // 遍历重量容量
            for (int k = 0; k <= V; k++) { // 遍历体积容量
                if (j < w[i] || k < c[i]) {
                    // 如果当前物品的重量或体积超过当前容量，则不能放入，继承前一行的值
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    // 如果当前物品可以放入，选择是否放入该物品来获得最大价值
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - w[i]][k - c[i]] + v[i]);
                }
            }
        }
    }

    // 输出在给定重量和体积限制下能够获得的最大价值
    cout << dp[n][m][V] << endl;
    return 0;
}