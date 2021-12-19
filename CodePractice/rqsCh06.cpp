//
// Created by 马鸿英 on 2021/12/12.
//
#include <iostream>
using namespace  std;
template <class T,class T1, class T2>
T max(T1 a, T2 b){
    return a > b ? a:b;
}

template <class T>
inline T min_(T a, T b) {return a < b?a:b;}


int main(){
    int  a = 1, b= 3;
    float aa = 3.3;
    int res = max<int, int, int>(a, b);
    auto res1 = max<float, float, int>(aa, b);
    cout<<res<<'\t'<<res1<<endl;
    cout<<min_(a, b)<<endl;

}