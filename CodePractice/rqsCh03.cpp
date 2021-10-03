//
// Created by 马鸿英 on 2021/10/2.
//

#include <iostream>
#include <cmath>
using namespace  std;

int main(){
    double a,b,c;
    cout<<"please input the equation:";
    cin>>a>>b>>c;
    if (a==0){
        return 0;
    }
    double delta = pow(b,2) - 4 * a * c;
    if (delta < 0){
        cout<<"no real root for the equation!";
        return 0;
    }
    else{
        double sqrtDelta = sqrt(delta);
        double x1, x2;
        x1 = (-b + sqrtDelta) / 2 / a;
        x2 = (-b - sqrtDelta) / 2/ a;
        cout<<"the root for the equation is x1="<<x1<<", x2="<<x2<<endl;
        return 0;
    }
}