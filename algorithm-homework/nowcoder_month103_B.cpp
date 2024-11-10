//
// Created by ASUS on 2024/10/25.
//
#include <bits/stdc++.h>
using namespace std;

//给定一个字符串，验证是否是电子邮箱。
int method(string str) {
    int a = static_cast<unsigned int>(static_cast<unsigned char>(str[0]));
    int b =static_cast<unsigned int>(static_cast<unsigned char>(str[str.size()-1]));
    if(a==64 || a==46)
        return 2;
    if(b==64 || b==45)
        return 2;
    char ch = '@';
    size_t found = str.find(ch);
    int count = 0 ;
    int count1 = 0;
    for ( int i = 0; i < found; ++i) {
        int y = static_cast<unsigned int>(static_cast<unsigned char>(str[found-1]));
        if(y==45)
            return 2;
        int x = static_cast<unsigned int>(static_cast<unsigned char>(str[i]));
        if( (x>=65 && x<=90) || x == 46 ) {
            count++;
        }else
            return 2;
    }
    for ( int i = found; i < str.size(); ++i) {
        int y = static_cast<unsigned int>(static_cast<unsigned char>(str[found]));
        if ( y== 45)
            return 2;

        int x = static_cast<unsigned int>(static_cast<unsigned char>(str[i]));
        if ( (x>=65 && x<=90) || x == 45 ) {
            count1++;
        }else
            return 2;
    }

    if (!((count >=1 && count1 <=64) && (count1 >= 1 && count1 <=255)) ) {
        return 2;
    }
    return 3;
}

int main() {
    int t;
    cin >> t;
    int arr[t];
    for  (int i = 0; i < t; ++i) {
        string str;
        getline(cin,str);
        arr[i] = method(str);
    }
    cout << endl;

    for  (int i = 0; i < t; i++) {
        if  (arr[i] == 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }





    return 0;
}
