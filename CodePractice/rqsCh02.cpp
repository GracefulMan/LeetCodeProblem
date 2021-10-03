//
// Created by 马鸿英 on 2021/10/2.
//

// typedef: rename for variable type name
#include <iostream>
typedef float F;
#define PI 3.1415926 // C style for constant.
const F pi=3.14; // C++ style for constant.






int main(){
    F radious=2, area;
    area = pi * radious * radious;
    // test
    F balance = 3.0;
    balance *= 2 + 2; // the result is 12. assignment ops is lower than arithmetic ops.
    std::cout<<balance<<std::endl;


    std::cout<<"the area of circle:"<<area<<std::endl;
    return 0;
}