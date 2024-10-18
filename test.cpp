//
// Created by ASUS on 2024/10/12.
//

#include <bits/stdc++.h>
using namespace std;

int method(int n){

    if(n==1) return 1;

    return n*method(n-1);
}

int main(){

    cout<<method(5);

    return 0;
}
