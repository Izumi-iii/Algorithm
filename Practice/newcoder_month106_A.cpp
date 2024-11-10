//
// Created by ASUS on 2024/12/6.
//

#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main() {
    int a,b,c,d;

    cin>>a>>b>>c>>d;

    int result= pow(a,b)*c+d;

    if(result%2 == 0){
        cout<<"NO";
    }else{
        cout<<"YES";
    }





    return 0;
}
