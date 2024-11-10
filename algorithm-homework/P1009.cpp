//
// Created by ASUS on 2024/10/19.
//
#include <bits/stdc++.h>
using namespace std;

long long method(long long n) {
    if (n==1)
        return 1;

    return method(n-1)*n;

}

int main() {
    int n ;
    cin>>n ;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += method(i);

    }

    cout << sum << endl;


    return 0;
}