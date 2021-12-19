//
// Created by 马鸿英 on 2021/10/2.
//title: recursive
//
#include <iostream>
#include <cmath>

using namespace std;

int getMaxValue(int *arr, int left, int right) {
    if (left == right) return arr[left];
    // take mid value, such ops can prevent overflow.
    int mid = left + ((right - left) >> 1); // Note: >> ops lower than +;
    int leftmax = getMaxValue(arr, left, mid);
    int rightmax = getMaxValue(arr, mid + 1, right);
    return leftmax > rightmax ? leftmax : rightmax;
}

void merge(int *arr, int left, int mid, int right) {
    int *res = new int[right - left + 1];
    int i = 0;
    int p0 = left, p1 = mid + 1;
    while (p0 <= mid && p1 <= right) {
        res[i++] = arr[p0] < arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <= mid) res[i++] = arr[p0++];
    while (p1 <= right) res[i++] = arr[p1++];
    for (int j = 0; j < right - left + 1; j++) {
        arr[left + j] = res[j];
    }

}

void mergeSort(int *arr, int left, int right) {
    if (left == right) return;
    else {
        int mid = left + ((right - left) >> 1);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

}

// 小和问题，详细看笔记
//tested
int mergeSmallSum(int *arr, int left, int mid, int right) {
    int *tmp = new int[right - left + 1];
    int p0 = left, p1 = mid + 1, i = 0;
    int res = 0;
    while (p0 <= mid && p1 <= right) {
        res += arr[p0] < arr[p1] ? arr[p0] * (right - p1 + 1) : 0;
        tmp[i++] = arr[p0] < arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <= mid) tmp[i++] = arr[p0++];
    while (p1 <= right) tmp[i++] = arr[p1++];

    for (int j = 0; j < right - left + 1; j++)
        arr[left + j] = tmp[j];
    delete[] tmp;
    return res;
}

int getSmallSum(int *arr, int left, int right) {
    if (left == right) return 0;
    else {
        int mid = left + ((right - left) >> 1);
        int leftSmallSum = getSmallSum(arr, left, mid);
        int rightSmallSum = getSmallSum(arr, mid + 1, right);
        int mergeSum = mergeSmallSum(arr, left, mid, right);
        return leftSmallSum + rightSmallSum + mergeSum;
    }
}

int BruteSearchForSmallSum(int *arr, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            res += arr[j] < arr[i] ? arr[j] : 0;
        }
    }
    return res;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
    cout << endl;
}

//逆序对问题
void BruteSearchForInversePair(int *arr, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                cout << "{" << arr[i] << "," << arr[j] << "}\t";
            }
        }
}

void mergeInversePair(int *arr, int left, int mid, int right) {
    int *tmp = new int[right - left + 1];
    int p0 = left, p1 = mid + 1, i = 0;
    while (p0 <= mid && p1 <= right) {
        if (arr[p0] > arr[p1]) {
            int index = p1;
            while (index <= right) {
                cout << "{" << arr[p0] << "," << arr[index] << "}\t";
                index++;
            }
        }
        tmp[i++] = arr[p0] > arr[p1] ? arr[p0++] : arr[p1++];
    }
    while (p0 <= mid) tmp[i++] = arr[p0++];
    while (p1 <= right) tmp[i++] = arr[p1++];
    for (int j = 0; j < right - left + 1; j++) {
        arr[left + j] = tmp[j];
    }
    delete[] tmp;
}

void InversePair(int *arr, int left, int right) {
    if (left == right) return;
    else {
        int mid = left + ((right - left) >> 2);
        InversePair(arr, left, mid);
        InversePair(arr, mid + 1, right);
        mergeInversePair(arr, left, mid, right);
    }
}

// 荷兰国旗问题，让数组左侧都小于某个数，右侧都大于某个数，其余数放中间

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int DutchFlagProblem(int *arr, int left, int right, int value) {
    int left_border = left - 1, right_border = right + 1;
    int current = left;
    while (current < right_border) {
        if (arr[current] < value) {
            left_border += 1; //边界向右边移动一位
            swap(arr, left_border, current);
            current++;
        } else if (arr[current] > value) {
            right_border -= 1; //右边界左移一位
            swap(arr, right_border, current);
        } else {
            current++;
        }
    }
    return current;
}



int DutchFlagEasyProb(int *arr, int left, int right, int value){
    int left_boarder = left - 1;
    for(int i=left; i<= right;i++){
        if(arr[i] <= value){
            swap(arr, i, left_boarder + 1);
            left_boarder++;
        }
    }
    return left_boarder;
}

void DutchFlagEasyProb2(int *arr, int left, int right, int value, int &leftb, int &rightb){
    int left_boarder = left - 1, right_board = right+1;
    int cur = left;
    while (cur < right_board){
        if(arr[cur] < value){
            swap(arr, cur++, ++left_boarder);
        }else if(arr[cur] == value) cur++;
        else{
            swap(arr, cur, --right_board);
        }
    }
    leftb = left_boarder;
    rightb = right_board;
}

void quickSortVersion1(int *arr, int left, int right){
    // 最差情况为O(N^2).
    if (left+1 >= right) return;
    int value = arr[right];
    int leftb, rightb;
    //最后一个数为基准，将小于的数放左边，大于放右边，等于放中间
    DutchFlagEasyProb2(arr, left, right-1, value, leftb, rightb);
    //交换最后一个数和右边区域的第一个数。
    swap(arr, right, rightb);
    //递归
    quickSortVersion1(arr, left, leftb-1);
    quickSortVersion1(arr, rightb+1, right);
}

void quickSortFinal(int *arr, int left, int right){
    if(left >= right) return;
    int index = rand() % (right - left + 1) + left ;
    int leftb, rightb;
    //leftb: =区的左边界，=区的右边界。
    swap(arr, index, right);
    DutchFlagEasyProb2(arr, left, right-1, arr[right], leftb,rightb);
    swap(arr, right, rightb);
    quickSortFinal(arr, left, leftb-1);
    quickSortFinal(arr, rightb + 1, right);
}



// simplify

void partition(int *arr, int left, int right, int &leftb, int &rightb){
    int value = arr[right];
    int cur = left, left_b = left - 1, right_b = right;
    while (cur < right_b){
        if(arr[cur] < value) swap(arr, cur++, ++left_b);
        else if(arr[cur] > value) swap(arr, cur, --right_b);
        else cur++;
    }
    swap(arr, right, right_b);
    leftb = left_b;
    rightb = right_b;
}

void quickSort(int *arr, int left, int right){
    if(left >= right) return;
    int leftb, rightb;
    swap(arr, left + rand() % (right - left + 1), right);
    partition(arr, left, right, leftb, rightb);
    quickSort(arr, left, leftb-1);
    quickSort(arr, rightb + 1, right);
}



int main() {
    int arr[] = {1, 3, 4, 2, 5, 2,3, 6, 8, 9, 5,12, -1, 4};
    int n = 14;
//    int value = 3;
//    quickSortVersion1(arr,0,n-1);
//    BruteSearchForInversePair(arr, n);
//    cout<<endl;
//    InversePair(arr, 0, n-1);
//    cout<<"Small Sum by BreteSearch:"<<BruteSearchForSmallSum(arr, n)<<endl;
//    cout<<"Small Sum:"<<getSmallSum(arr, 0, n-1)<<endl;
    quickSort(arr, 0, n-1);
    printArray(arr, n);


}