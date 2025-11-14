//
// Created by ASUS on 2025/11/14.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t,temp;
    cin>>t;
    int arr[t];
    for(int i=0;i< sizeof(arr) / sizeof(arr[0]);i++){
        cin>>temp;
        arr[i]=temp;
    }

    for(int i=0;i < sizeof(arr) / sizeof(arr[0]) ;i++){
        if(arr[i]==3 || arr[i]==6){
            cout << "koishiYun" << endl;
        }else{
            cout << "Kato_Shoko" << endl;
        }
    }




    return 0;
}