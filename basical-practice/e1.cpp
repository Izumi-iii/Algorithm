//
// Created by ASUS on 2025/3/1.
//
#include <bits/stdc++.h>
using namespace std;

bool isTrue(long long n1,long long n2){
    string s = to_string(n1) + to_string(n2);
    if(s.length() != 10) return false;
    sort(s.begin(),s.end());
    for (int i = 0; i < 10; i++) {
        if(s[i] != '0' + i) return false;
    }
    return true;
}

int main(){
    for (int i = 10; i < 30; i++) {
        long long cube = (long long )i*i*i;
        long long fourth = (long long )i*i*i*i;
        if (cube >= 1000 && cube <= 10000 && fourth>=100000 && fourth <1000000){
            if (isTrue(cube,fourth)){
                cout << i << "," << cube << "," << fourth << endl;
                return 0;
            }
        }

    }

}