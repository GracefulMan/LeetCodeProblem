//
// Created by 马鸿英 on 2021/11/20.
//
#include <queue>
#include <iostream>

void swap(int *arr, int i , int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapInsert(int *arr, int index){
    while (arr[index] > arr[(index - 1) / 2]){
        //如果比老爹的值大，就和老爹交换呗
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
void heapify(int *arr, int index, int heapSize){
    int left = 2 * index + 1; // 左孩子下标
    while (left < heapSize){ //下面还有孩子的时候
        //左右孩子中找较大孩子的下标。（还得判断有没有右孩子）
        int largest = left + 1 < heapSize && arr[left] < arr[left+1]? left + 1: left;
        // 找父节点和较大孩子之间较大值的下标
        largest = arr[largest] > arr[index]?  largest:index;
        // 如果这个较大值是父节点本身，说明父节点的左右孩子都已经比他小了，位置已经合适了。
        if(largest == index) break;
        // 否则就说明还是孩子大，将父亲和孩子位置做交换。
        swap(arr, largest, index);
        index = largest;//父节点变成刚才和她交换的那个孩子位置
        left = index * 2 + 1; // 继续求出她的孩子，进行下一轮循环。
    }
}

void heapSort(int *arr, int n){
    // 先把数组整体范围形成大顶堆。但是大顶堆不一定有序。
//    for(int i=0;i<n;i++){ // O(N)
//        heapInsert(arr, i); // O(log N)
//    }
    // 这个更快,时间复杂度为O(N)
    for(int i=n-1; i>=0;i--){
        heapify(arr, i, n);
    }
    int heapSize = n;
    swap(arr, 0, --heapSize);
    while (heapSize > 0){ // O(N)
        heapify(arr, 0, heapSize); //O(log N)
        swap(arr, 0, --heapSize);
    }
}

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<std::endl;
}

int main(){
    int arr[] ={1, 4, -2, 5, 7, 11, 3, 6, 9, 0};
    int n = 10;
    heapSort(arr, n);
    printArray(arr, n);
}