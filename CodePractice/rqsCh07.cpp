//
// Created by 马鸿英 on 2021/12/19.
//
#include <iostream>
using namespace std;
void test1(){
    int x= 5;
    int *p;
    p = &x;
    cout << "the address of x:"<<p<<endl;
    cout<<*p<<endl;
}


void arrayAndPtr(){
    int arr[] = {1,2,3, 4, 5};
    int *p;
    // the arr indicate a constant ptr.
    p = arr;
    /*指针+1表示数组中指针指向元素的下一元素地址；
     * 指针-1表示数组中指针指向元素的上一元素地址；
     * 合法的指针操作：p + k, p - k, p1 - p2
     * */
    for(int i=0;i<5;i++) {
        cout << *(p + i) << '\t';
        cout << p[i] << '\t';
    }
}

void swap1(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void swap2(int &a, int &b){
    //形式参数和实际参数共享一块空间.起别名。
    int c;
    c = a;
    a = b;
    b = c;
}

int maxVal(int a[], int left, int right){
    if(right == left) return a[left];
    else{
        int mid = left + ((right  - left) >> 1);
        int leftMax = maxVal(a, left, mid);
        int rightMax = maxVal(a, mid + 1, right);
        return max(leftMax, rightMax);
    }
}

int *getMax(int *a, int *b, int *c){
    //当函数的返回值是指针时，返回地址对应的变量不能是被调函数的局部变量
    int *p;
    if(*a > *b) p=a;
    else p = b;
    if(*c > *p) return c;
    return p;
}

int *getMin(int *a, int *b, int *c){
    int *p;
    if(*a < *b) p=a;
    else p = b;
    if(*c < *p) return c;
    return p;
}

int main(){
    test1();
    arrayAndPtr();
    int a =5, b= 3;
    cout<<"a:"<<a<<"\tb:"<<b<<endl;
    swap1(&a, &b);
    cout<<"a:"<<a<<"\tb:"<<b<<endl;
    swap2(a, b);
    cout<<"a:"<<a<<"\tb:"<<b<<endl;
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 5};
    cout<<maxVal(arr, 0, 9)<<endl;
    //找出变量a, b, c中的最大值和最小值，并交换两个变量的值
    int a1=1, b1=2, c1= 3;
    swap1(getMax(&a1, &b1, &c1), getMin(&a1, &b1, &c1));
    cout<<"a:"<<a1<<"\tb1:"<<b1<<"\tc1:"<<c1<<endl;






}