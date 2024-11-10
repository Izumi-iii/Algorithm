//
// Created by ASUS on 2024/12/13.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n,a,b,c;
    cin >> n >> a >> b >> c;
    int count = 0;
    bool flag = true;
    while (flag) {
        if(n>=a) {
            n -= a;
            count++;
            continue;
        } else if(n < a && n >= b) {
            n -= b;
            count++;
            continue;
        } else if(n < b && n >= c) {
            n -= c;
            count++;
            continue;
        } else {
            flag = false;
        }

    }

    cout << count << endl;


    return 0;
}