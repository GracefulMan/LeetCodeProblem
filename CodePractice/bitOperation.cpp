//
// Created by 马鸿英 on 2021/9/15.
//
#include <iostream>
#include "math.h"
using namespace  std;

int onlyOneDigits(int *arr, int n){
    int res = 0;
    for(int i=0; i < n; i++){
        res ^= arr[i];
    }
    return res;
}



void twoOnlyDigits(int *arr, int n){

    int res = 0;
    for (int i=0;i < n; i++){
        res ^= arr[i];
    }
    int right_one = (~res + 1) & res;
    int only_one = 0;
    for(int i=0;i<n;i++){
        if((arr[i] & right_one) !=0){
            only_one ^= arr[i];
        }
    }
    cout<<only_one << " "<<(res ^ only_one)<<endl;



}

int generator(int *arr,int length){
    int tmp;
    for(int i=0;i<(length-1)/2;i++) {
        tmp = rand() % 100;
        arr[i] = tmp;
        arr[length - i - 2] = tmp;
    }
    int index = rand() % length;
    int value = 100 + rand() % 100;
    arr[length-1] = arr[index];
    arr[index] = value;

    return value;
}




int main(){
    int *arr;
    int n=121;
    arr = new int[n];
    int truth = generator(arr, n);
    int value = onlyOneDigits(arr, n);
    cout<<"truth: "<<truth<<"  found: "<<value<<endl;
    int b[]={1, 1, 2, 3, 4, 4, 5, 6, 5 ,6};
    twoOnlyDigits(b,10);
}