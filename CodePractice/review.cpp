//
// Created by 马鸿英 on 2021/10/3.
//
#include <iostream>
using namespace std;

// bit operations
/*
properties:
 * N^0=N N^N=0.
 * 结合律和交换律
 *
 * */
//1. swap the variable values.

void swap(int *arr, int i, int j){
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

//2. find the digit which appear only once while all others appear twice.

// tested!
int onlyOnceDigits(int *arr, int n){
    int res = 0;
    for(int i=0;i<n;i++)
        res ^= arr[i];
    return res;
}
//3. find two digits which appear only once while all others appear twice.

// tested!
int onlyOnceTwoDidits(int *arr, int n){
    int res = 0;
    for(int i=0;i<n;i++)
        res ^= arr[i];
    int rightFirstOne = (~res + 1) & res;
    int onceDigit = 0;
    for(int i=0;i<n;i++){
        if ((rightFirstOne & arr[i]) == 0){
            onceDigit ^= arr[i];
        }
    }
    int anotherRes = (res ^ onceDigit);
    cout<<"two digits:"<<anotherRes<<'\t'<<onceDigit<<endl;
}

// sort algorithms.

//tested
void selectSort(int *arr, int n){
    for(int i=0;i<n;i++)
        for(int j=i+1; j<n;j++)
            if(arr[j]<arr[i])
                swap(arr, i, j);
}

// tested;
void bubbleSort(int  *arr, int n){
    for(int i=n-1;i>0;i--){
        bool flag = true;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr, j, j + 1);
                flag = false;
            }
        }
        if (flag) break;
    }
}

// recursive application
/*
 * complexity theorem:
 * Master equation: T(N) = a * T(N/b) + O(N^d)
 * if log_b a < d, complexity=O(N^d)
 * if log_b a > d, complexity=O(N^log_b a)
 * if log_b a =d, complexity= O(N^d log N)
 */

//tested;
int getMaxValue(int *arr, int left, int right){
    // a = 2, b=2, d=0, log _b a=1>0, complexity: O(N)
    if(left == right) return arr[left];
    else{
        int mid = left + ((right - left)>>1);
        int leftMaxValue = getMaxValue(arr, left, mid);
        int rightMaxValue = getMaxValue(arr, mid + 1, right);
        return leftMaxValue > rightMaxValue?leftMaxValue : rightMaxValue;
    }
}

void merge(int *arr, int left, int mid, int right){
    int *res = new int [right - left + 1];
    int p0=left, p1=mid+1, i=0;
    while (p0 <= mid && p1 <= right){
        res[i++] = arr[p0] < arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <= mid)
        res[i++] = arr[p0++];
    while (p1 <=right)
        res[i++] = arr[p1++];
    for(int j=0;j<right - left + 1; j++){
        arr[j + left] = res[j];
    }
    delete [] res;
}

//tested;
void mergeSort(int *arr, int left, int right){
    /*
     * a = 2, b=2, d=1; log_b a=1 == d,
     * complexity = O(N^d log N)=O(N log N)
     * */

    if(left == right) return;
    else{
        int mid = left + ((right - left)>>1);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<'\t';
    cout<<endl;
}


int main(){
    int arr[]={1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 10, 8, 6, 4, 2, 9, 7, 5, 3, 1, 42, 24};
    int n=22;
    cout<<getMaxValue(arr, 0, n-1);


}



