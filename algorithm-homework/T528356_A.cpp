
#include <iostream>

using namespace std;

void methodY(int a) {
    a += 5;
    a = a*3;
    cout << a << " ";

}



void methodL(int b) {
    b = b*3;
    b += 5 ;
    cout << b << endl;
}

int main() {
    int a,b;
    cin >> a;
    b=a;


    methodY(a);
    methodL(b);




    return 0;
}