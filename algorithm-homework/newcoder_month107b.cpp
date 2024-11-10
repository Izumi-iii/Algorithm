//
// Created by ASUS on 2024/12/13.
//

#include <bits/stdc++.h>
using namespace std;

long long method(long long arr[]) {
    long long sum = 0;
    for (int i = 0;i < sizeof(arr) ; i++) {
        sum += arr[i];
    }
    return sum / sizeof(arr);

}

void add(long long arr[],int num) {
    for (int i = 0;i < sizeof(arr) ; i++) {
        int flag = 0 ;

        if(arr[i] > num) {
            arr[i]--;
            flag++;
        }
        if (flag)
            count++;


    }
}

void jian(long long arr[],int num) {
    for (int i = 0;i < sizeof(arr) ; i++) {
        int flag = 0 ;

        if(arr[i] < num) {
            arr[i]++;
            flag++;
        }
        if (flag)
            count++;

    }
}

int main() {
    long long n,average;
    cin >> n;
    cout << endl;
    long long arr[n];

    for (int i = 0;i < n ; i++) {
        cin >> arr[i];
    }

    int count = 0;





    cout << count << " " << average<< endl;





    return 0;
}