//
// Created by ASUS on 2025/3/1.
//
#include "bits/stdc++.h"
using namespace std;

int main(){

    for(int i = 1; i < 30 ; i++){
        for (int j = i+1; j <30 ; j++) {
            if(i*j == 6*(i+j) && j-i <= 8){
                cout << i <<  "," <<  j << endl;
            }
        }

    }

    return 0;
}