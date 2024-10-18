
#include <bits/stdc++.h>
using namespace std;

int method(int n,int a,int b) {

    if(b == 0 && a <= n) {
        cout << a << endl;
        return 0;
    }


    if (a>n || (b>a && b>n-a) ) {
        cout << "No solution" << endl;
        return 0;
    }


    int x = a-b ;

    cout << a-x+1 << " ";
    if(a+x <= n) {
        cout << a+x-1 << endl;
    }



}


int main() {
    int n,a,b;
    cin>>n>>a>>b;


    method(n,a,b);






    return 0;
}