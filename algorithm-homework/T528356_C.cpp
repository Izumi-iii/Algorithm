//
// Created by ASUS on 2024/10/18.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,min_d,count;
    min_d = 100;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int w,d,x;
        cin >> w >> d;
        x=(d-1)*7+w+1;
        arr.push_back(x);
    }

    int min = arr[0];
    for (int i = 1; i < arr.size(); i++) {
         if (arr[i] < min)
             min = arr[i];
    }




    cout << min << endl;





    return 0;
}
