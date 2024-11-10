//
// Created by ASUS on 2025/3/1.
//
#include "bits/stdc++.h"
using namespace std;

int main(){
    int cnt = 0;
    for (int i = 1; i < 2021; i++) {
        string s = to_string(i);
        cnt += count(s.begin(),s.end(),'2');
    }

    cout << cnt << endl;
    return 0;

}
