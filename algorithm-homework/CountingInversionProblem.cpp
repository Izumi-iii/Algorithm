//
// Created by ASUS on 2024/10/12.
//
#include <iostream>
#include <vector>
using namespace std;

//利用分治策略解决计算数组中 ---逆序对计数问题Counting Inversion Problem

//归并两个 有序 数组，并且计算逆序对
int MergeAndSort(vector<int>& arr,vector<int>& temp,int left,int mid,int right) {
    int count = 0;
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
            count += (mid-i+1);//这一步很重要，我们把右子数组中比左子数组中当前元素小的元素个数，加到count中，
                             //因为此时右子数组中元素比左子数组中当前元素小，所以此时左子数组中当前元素和右子数组中元素构成逆序对
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

    //返回我们再排序过程中记录的逆序对个数
    return count ;
}


//利用递归思想拆分数组，并调用MergeAndSort方法计数逆序对个数  注意理解递归思想在这里面的实现
int MergeCountAndSort(vector<int>& arr,vector<int>& temp,int left,int right) {
    int count = 0 ;

    //判断递归结束的条件，左右指针重合的时候，即数组中只有一个元素
    if(left<right) {

        int mid = (left+right)/2;

        //递归操作继续拆分 左部数组，并计算逆序对个数
        //如果能理解这里的调用MergeCountAndSort可以计数逆序对个数，恭喜你，就理解了这里的递归思想了！
        count += MergeCountAndSort(arr,temp,left,mid);

        //递归操作继续拆分 右部数组，并计算逆序对个数
        count += MergeCountAndSort(arr,temp,mid+1,right);

        //合并两个有序数组，并计算 两个部分总的 逆序对个数
        //这里也是本题中递归的思想的重点 好好想一想这三行代码的执行先后逻辑！
        count += MergeAndSort(arr,temp,left,mid,right);


    }

    return count;

}

//主函数，也可以没有这一个函数，这是为了main函数中代码的简洁加上的
int CountInversion(vector<int>& arr) {

    //这里定义了我们的目标数组，
    //注意这个数组定义之后只有长度没有值
    vector<int> temp(arr.size());

    //调用MergeCountAndSort计算逆序对方法并返回结果
    return MergeCountAndSort(arr,temp,0,arr.size()-1);

}

int main() {

    vector<int> arr = {7,5,6,4,9,1,3};

    int result = CountInversion(arr);

    cout << "数组中的逆序对个数为: " << result << endl;

    return 0;
}
