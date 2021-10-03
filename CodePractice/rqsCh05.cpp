//
// Created by 马鸿英 on 2021/10/2.
//



#include <iostream>

using namespace std;

int orderSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return target;
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}


void selectionSorted(int arr[], int n) {
    // every time select the minimum value.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void bubbleSorted(int arr[], int n) {
    // two-two compare and bubble max to last.
    for (int i = n - 1; i > 0; i--) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
}

void matrixMul(int arr1[2][3], int row1, int col1, int arr2[3][2], int row2, int col2, int res[2][2]){
    if (col1 != row2) return;
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            res[i][j] = 0;
            for(int k=0; k< col1;k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}


int main() {
//    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
//    int n = 10;
//    bubbleSorted(a, n);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << '\t';
//    }
//    cout << endl;
//    int index = binarySearch(a, n, 2);
//    cout << index << endl;
//    return 0;
    int a[2][3] = {
            {1, 2, 3},
            {3, 4, 5}
    };
    int b[3][2] = {
            {1 ,2},
            {3, 4},
            {5, 6}
    };
    int res[2][2]={0};
    matrixMul(a, 2, 3, b, 3, 2,res);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<< res[i][j]<<'\t';
        }
        cout<<endl;
    }




}