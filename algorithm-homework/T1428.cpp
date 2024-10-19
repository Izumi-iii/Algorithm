#include <bits/stdc++.h>

using namespace std;

int method(vector<int>& fish, vector<int>& cute) {
    for ( int i = 0; i < fish.size(); i++) {
        if(i==0) {
            cute[i]=0;
        }else {
            int count=0;
            for ( int j = 0; j < i; j++) {
                if (fish[j]<fish[i])
                    count++;
            }
            cute[i]= count;
        }
    }


    return 0;
}


int main() {
    int n;
    cin >> n;
    vector<int> fish;
    vector<int> cute(n);


    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        fish.push_back(temp);
    }

    method(fish, cute);
    for (int i = 0; i < n; i++) {
        cout << cute[i] << " ";
    }




    return 0;
}
