#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    int temp[n][m]={0};
    temp[0][3]=0;
    temp[0][2]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for (int k=0;k<n;k++) {
                for ( int l=0;l<m;l++) {
                    if (arr[i][j] == arr[k][l]) {
                        int distance = (k-i) * (k-i) + (l-j) * (l-j);
                        temp[i][j]=max(temp[i][j],distance);
                    }
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
