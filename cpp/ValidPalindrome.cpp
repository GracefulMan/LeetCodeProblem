//
// Created by 马鸿英 on 2019/3/5.
//

#include <iostream>
using namespace std;
bool isPalindrome(string s) {
    int length =s.size();
    string myString = "";
    for(int i=0;i<length;i++){
        if('A'<=s[i]&&s[i]<='Z') myString+=(s[i]+32);
        else if('a'<=s[i]&&s[i]<='z') myString+=s[i];
        else if('0'<=s[i]&&s[i]<='9') myString+=s[i];
    }
    length = myString.size();
    for(int i=0,j=length-1;i<j;i++,j--){
        if(myString[i]!=myString[j]) return false;
    }
    return true;
}
int main(){
    cout<<isPalindrome("0P");
}
