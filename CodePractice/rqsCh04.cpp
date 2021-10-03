//
// Created by 马鸿英 on 2021/10/2.
//

#include <iostream>
#include <cmath>

double exp_(double x){
    // taylor expansion for e^x.
    double powTmp = x;
    int fat = 1;
    double res = 1;
    while (powTmp / fat > 1e-10){
        res += powTmp / fat;
        powTmp *= powTmp;
        fat *= fat + 1;
    }
    return res;
}

int main(){
    double x(0.01);
    double res = exp_(x);
    std::cout<<res<<std::endl;
    std::cout<<exp(x)<<std::endl;
}
