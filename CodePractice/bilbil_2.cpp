//
// Created by 马鸿英 on 2021/10/2.
//title: recursive
//
#include <iostream>
#include <cmath>
using namespace  std;

int getMaxValue(int *arr, int left, int right){
    if (left == right) return arr[left];
    // take mid value, such ops can prevent overflow.
    int mid = left + ((right - left) >> 1); // Note: >> ops lower than +;
    int leftmax = getMaxValue(arr, left, mid);
    int rightmax = getMaxValue(arr, mid + 1, right);
    return leftmax > rightmax? leftmax : rightmax;
}

void merge(int *arr, int left, int mid, int right){
    int *res = new int[right - left + 1];
    int i=0;
    int p0 = left, p1 = mid + 1;
    while (p0 <= mid && p1 <= right){
        res[i++] = arr[p0] < arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <=mid) res[i++] = arr[p0++];
    while (p1 <= right) res[i++] = arr[p1++];
    for(int j=0;j<right - left + 1; j++){
        arr[left + j] = res[j];
    }

}

void mergeSort(int *arr, int left, int right){
    if(left == right) return;
    else {
        int mid = left + ((right - left) >> 1);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

}

int main(){
    int arr[] = {1,3,4,322,3,1,54, 435};
    int res = getMaxValue(arr, 0, 8);
    mergeSort(arr, 0, 7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl<< res<<endl;
}