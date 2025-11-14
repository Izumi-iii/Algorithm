//
// Created by ASUS on 2025/11/14.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
    int u,n;

    cin>>u;
    while(u){
        cin>> n;
        long long sum = 0;
        vector<array<long long, 2>> arr;
        for (int i = 0; i < n; i++) {
            long long a,b;

            cin>>a>>b;
            // 创建一个包含 a 和 b 的新 array<int, 2>
            array<long long, 2> temp = {a, b};
            // 使用 push_back 将新元素添加到向量末尾
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end(), [](const array<long long, 2>&a, const array<long long, 2>&b) {
            // 按照第二列 (索引 1) 降序排序
            return a[1] > b[1];
        });

        for (int i = 0; i < n; i++) {
            sum += arr[i][0] - arr[i][1] * i ;
        }
        cout << sum << endl;
        u--;
    }



    return 0;
}
