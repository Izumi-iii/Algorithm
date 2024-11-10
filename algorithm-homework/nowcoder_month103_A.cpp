//
// Created by ASUS on 2024/10/25.
//
#include <bits/stdc++.h>
using namespace std;

int method(vector<int>& stick){
    sort(stick.begin(), stick.end());
    for (int i = 0; i < stick.size()-2; i++) {
        if(stick[i] == stick[i+1] && stick[i+1] == stick[i+2]){
            return stick[i]*3;
        }

    }
    return 0;


}

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vector<int> stick(t);
        for (int j = 0; j < t; j++) {
            int x;

            cin >> x;
            stick[j] = x;

        }
        int result = method(stick);
        if (result != 0){
            arr[i] = result;
        }else{
            arr[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if(arr[i]==0){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
            cout << arr[i] << endl;
        }
    }


    return 0;
}