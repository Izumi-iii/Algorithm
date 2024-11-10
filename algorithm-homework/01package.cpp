//
// Created by ASUS on 2024/11/10.
//
#include <bits/stdc++.h>
using namespace std;
//定义物品重量、价值数组，以及动态规划的背包二维数组dp
int w[99],v[99],dp[299][299];


int main() {
    int m,n;
    //输入背包的容量和物品的数量
    cin>>m>>n;
    //输入物品的重量以及价值
    for (int i = 0;i<n;i++) {
        cin>>w[i]>>v[i];
    }
    //二层循环遍历寻找大容量为m的背包中能够获得的最大价值
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {

            //边界情况，物品0或背包容量0，直接返回0
            if(i==0||j==0) {
                dp[i][j]=0;
            }
            else if(j<w[i]) {
                //如果放不下,就不放，继承上一层的值
                dp[i][j]=dp[i-1][j];
            } else {
                //如果放得下,取两种情况中的较大值（即选择是否放入该物品后能否获得最大的价值）
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=m;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
    return 0;
}