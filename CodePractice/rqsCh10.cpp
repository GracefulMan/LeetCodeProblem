//
// Created by 马鸿英 on 2022/2/7.
//

#include <iostream>
using namespace  std;

class Rational{
    friend Rational operator-(const Rational &a, const Rational &b){
        Rational res;
        res.num = a.num * b.den - a.den * b.num;
        res.den = a.den * b.den;
        res.RreductFration();
        return res;
    }
    friend Rational operator/(const Rational &a, const Rational &b){
        Rational tmp(b.den, b.num);
        return a * tmp;
    }
private:
    int num;
    int den;
    const double pi;
    void RreductFration(){
        for(int i = den; i >1;i--){
            if(den % i == 0 && num % i == 0)
            {
                num /= i;
                den /= i;
                break;
            }
        }
    }
public:
    Rational():num(1),den(1),pi(3.14){}
    Rational(int num, int den=1):num(num), den(den), pi(3.14){
        //如果没有初始化列表，则类的属性会用默认的构造函数赋个初值，然后再会在这个构造函数中进行初始化，而用初始化列表能够直接赋值。
        //其次，类常量只能用初始化列表。
        RreductFration();
    }
    Rational(const Rational &p):pi(3.14) {
        num = p.num;
        den = p.den;
        cout<<"拷贝构造函数"<<endl;
    }
    Rational operator+(const Rational &p)const {
        //引用传递不会再次调用拷贝构造函数.
        Rational res;
        res.den = p.den * den;
        res.num = p.num * den + p.den * num;
        res.RreductFration();
        return res;
    }
    Rational operator*(const Rational & p) const{
        Rational res;
        res.den = p.den * den;
        res.num = p.num * num;
        res.RreductFration();
        return res;
    }
    Rational & operator=(const Rational &p){
        if(this == &p) return *this;
        num = p.num;
        den = p.den;
        return *this;
    }

    friend ostream & operator<<(ostream &os, const Rational &p){
        if(p.den == 1)
            os << p.num;
        else
            os << p.num << "/"<< p.den;
        return os;
    }
    operator double () const{
        cout<<"convert to double"<<endl;
        return (double) num / den;
    }

    operator int () const{
        cout<<"convert to int"<<endl;
        return num / den;
    }
};

int main(){
    Rational a(6, 9);
    Rational b(1, 4);
    Rational c = a + b, d(a);
    cout<< c<<endl;
    cout<< a * b<<endl;
    cout<< a / b<<endl;
    cout<<double ((a + b) * c + a / d)<<endl;



}