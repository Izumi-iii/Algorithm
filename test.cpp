#include "iostream"
using namespace std;

int main() {
    int arr[]={1,2,3,4,5,6,7,8};
    int *p=arr;
    int max = *p;
    for (int i = 1; i < 8; ++i) {
        if (max < *(p+i)){
            max = *(p+i);
        }
    }
    cout << max << endl;
    return 0;
}