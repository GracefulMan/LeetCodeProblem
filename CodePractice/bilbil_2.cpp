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
// 小和问题，详细看笔记
//tested
int mergeSmallSum(int *arr, int left, int mid, int right){
    int *tmp = new int [right - left + 1];
    int p0=left, p1=mid+1, i=0;
    int res = 0;
    while (p0 <= mid && p1 <= right){
        res += arr[p0] < arr[p1] ? arr[p0] * (right - p1 + 1) : 0;
        tmp[i++] = arr[p0] < arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <= mid) tmp[i++] = arr[p0++];
    while (p1 <= right) tmp[i++] = arr[p1++];

    for(int j=0; j < right - left + 1; j++)
        arr[left + j] = tmp[j];
    delete [] tmp;
    return res;
}

int getSmallSum(int *arr, int left, int right){
    if(left == right) return 0;
    else{
        int mid = left +((right - left) >> 1);
        int leftSmallSum = getSmallSum(arr, left, mid);
        int rightSmallSum = getSmallSum(arr, mid + 1, right);
        int mergeSum = mergeSmallSum(arr, left, mid, right);
        return leftSmallSum + rightSmallSum + mergeSum;
    }
}

int BruteSearchForSmallSum(int *arr, int n){
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i;j++) {
            res += arr[j] < arr[i] ? arr[j] : 0;
        }
    }
    return res;
}

void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<'\t';
    cout<<endl;
}

//逆序对问题
void BruteSearchForInversePair(int *arr, int n){
    for(int i=0;i<n; i++)
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                cout<<"{"<<arr[i]<<","<<arr[j]<<"}\t";
            }
        }
}
void mergeInversePair(int *arr, int left, int mid, int right){
    int *tmp = new int [right - left + 1];
    int p0=left, p1=mid+1, i=0;
    while (p0 <= mid && p1 <= right){
        if(arr[p0] > arr[p1]){
            int index = p1;
            while (index <= right){
                cout <<"{"<<arr[p0]<<","<<arr[index]<<"}\t";
                index++;
            }
        }
        tmp[i++] = arr[p0] > arr[p1] ? arr[p0++]: arr[p1++];
    }
    while (p0 <= mid) tmp[i++] = arr[p0++];
    while (p1 <= right) tmp[i++] = arr[p1++];
    for(int j=0;j< right - left + 1; j++){
        arr[left + j] = tmp[j];
    }
    delete [] tmp;
}

void InversePair(int *arr, int left ,int right){
    if (left == right) return;
    else{
        int mid = left + ((right - left)>>2);
        InversePair(arr, left, mid);
        InversePair(arr, mid + 1, right);
        mergeInversePair(arr, left, mid, right);
    }
}


int main(){
    int arr[] = {1,3,4,2, 5};
    int n = 5;
    BruteSearchForInversePair(arr, n);
    cout<<endl;
    InversePair(arr, 0, n-1);
//    cout<<"Small Sum by BreteSearch:"<<BruteSearchForSmallSum(arr, n)<<endl;
//    cout<<"Small Sum:"<<getSmallSum(arr, 0, n-1)<<endl;
    printArray(arr, n);


}