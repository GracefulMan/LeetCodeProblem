//
// Created by 马鸿英 on 2019/1/31.
//
/*I             1
V             5
X             10
L             50
C             100
D             500
M             1000
IV            4
IX            9
XL             40
XC              90
CD              400
CM              900*/
#include <iostream>
using namespace std;
int romanToInt(string s) {
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        bool judge = false;
        if(s[i]=='I'&&s[i+1]=='V') {sum+=4;judge=true;};
        if(s[i]=='I'&&s[i+1]=='X') {sum+=9;judge=true;};
        if(s[i]=='X'&&s[i+1]=='L') {sum+=40;judge=true;};
        if(s[i]=='X'&&s[i+1]=='C') {sum+=90;judge=true;};
        if(s[i]=='C'&&s[i+1]=='D') {sum+=400;judge=true;};
        if(s[i]=='C'&&s[i+1]=='M') {sum+=900;judge=true;};
        if(judge) i+=1;
        else{
            switch (s[i]){
                case 'I':sum+=1;
                    break;
                case 'V':sum+=5;
                    break;
                case 'X':sum+=10;
                    break;
                case 'L':sum+=50;
                    break;
                case 'C':sum+=100;
                    break;
                case 'D':sum+=500;
                    break;
                case 'M':sum+=1000;
                    break;
                default:break;
            }
        }
    }

    return sum;
}

int main(){
    cout<<romanToInt("MCMXCIV");
}