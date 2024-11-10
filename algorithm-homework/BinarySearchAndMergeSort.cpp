//
// Created by ASUS on 2024/10/30.
//
#include <bits/stdc++.h>
using namespace std;

//二分查找方法：输入一个有序数组以及目标数，返回目标数的下标。
//
int binarySearch(vector<int>& arr, int left, int right, int target)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

//分治排序
void Sort(vector<int>& arr,vector<int>& temp , int left, int mid, int right) {
    int i = left;//定义左子数组的起始点
    int k = left;//合并后的数组的起始点
    int j = mid+1;//定义右子数组的起始点

    while(  i<=mid && j<=right) {
        if(arr[i]<= arr[j]) {
            temp[k]=arr[i];//注意这里k的作用，我们将较小的元素放入我们一开始定义的空数组temp中
            k++;//k向后移位
            i++;//i向后移位 之后的移位操作不再注释
        }else {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    //在上面的while循环中，i<=mid 和 j<=right这两个条件只要有一个不成立循环就会结束，
    //换言之就是两个子数组中的元素不能全部复制到temp数组中去，我们需要把剩下的元素复制到temp数组中，如下操作：
    while(i<=mid) {
        temp[k]=arr[i];
        k++;
        i++;
    }

    while (j<=right) {
        temp[k]=arr[j];
        k++;
        j++;
    }

    //到这里，temp数组中是有序数组了，但是之后的操作中我们还是以arr为操作目标，而arr中的顺序还是混乱状态
    //我们需要把已经操作过的元素进行排序操作，最简单的方法就是从temp中将元素复制到arr中，如下：
    for(int i=left;i<=right;i++) {
        arr[i]=temp[i];
    }

}

void Merge(vector<int>& arr,vector<int>& temp,int left,int right) {


    //判断递归结束的条件，左右指针重合的时候，即数组中只有一个元素
    if(left<right) {

        int mid = (left+right)/2;

        Merge(arr,temp,left,mid);
        Merge(arr,temp,mid+1,right);
        Sort(arr,temp,left,mid,right);
    }
}

//主函数，也可以没有这一个函数，这是为了main函数中代码的简洁加上的
void Inversion(vector<int>& arr,int target) {

    //这里定义了我们的目标数组，
    //注意这个数组定义之后只有长度没有值
    vector<int> temp(arr.size());

    //调用Merge,对数组进行排序
    Merge(arr,temp,0,arr.size()-1);

    //调用binarySearch，得到目标数字的下标
    int result = binarySearch(arr, 0, arr.size()-1, target);
    cout << result << endl;
}


int main() {
    //输入对应的数据
    //第一行输入数组大小与目标数字
    int n,target;
    cin >> n,target;
    vector<int> arr;
    //接下来n行输入数组元素
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << endl;

    //调用主函数
    Inversion(arr,target);

    // //this is a test 打印排序后的数组
    // for (int i = 0;i<arr.size();i++)
    //     cout << arr[i] << " ";

    return 0;
}
