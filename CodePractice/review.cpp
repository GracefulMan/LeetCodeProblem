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

int onlyOnceDigits(int *arr, int n){
    int res = 0;
    for(int i=0;i<n;i++)
        res ^= arr[i];
    return res;
}
//3. find two digits which appear only once while all others appear twice.

int onlyOnceTwoDidits(int *arr, int n){
    int res = 0;
    for(int i=0;i<n;i++)
        res ^= arr[i];
    int rightFirstOne = (~res + 1) & res;
    int onceDigit = 0;
    for(int i=0;i<n;i++){
        if ((rightFirstOne & arr[i]) != 0){
            onceDigit ^= arr[i];
        }
    }
    int anotherRes = res ^ onceDigit;
    cout<<"two digits:"<<anotherRes<<'\t'<<onceDigit<<endl;
}

// sort algorithms.




