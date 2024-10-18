//
// Created by ASUS on 2024/10/18.
//

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr,vector<int>& temp,int left,int mid,int right) {

    int i = left;
    int j = mid+1;
    int k = left;

    while(i<= mid && j<=right) {
        if(arr[i]<=arr[j]) {
            temp[k++] = arr[i++];
        }else {
            temp[k++] = arr[j++];
        }
    }

        while(i<=mid) {
            temp[k++] = arr[i++];
        }
        while (j<=right) {
            temp[k++] = arr[j++];
        }



}

void sort(vector<int>& arr,vector<int>& temp,int left,int right) {

    if(left<right) {

        int mid = left+(right-left)/2;
        sort(arr,temp,left,mid);
        sort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid,right);
    }

    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }

}

int main() {


    int n,m,x;
    cin >> n >> m;
    vector<int> arr;
    while(m--) {

        cin >> x;
        arr.push_back(x);
    }

    vector<int> temp(m);

    sort(arr,temp,0,arr.size()-1);




    return 0;
}
