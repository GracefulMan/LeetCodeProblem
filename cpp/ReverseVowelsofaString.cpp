#include <iostream>
#include <set>
#include <cstring>
using namespace std;


string reverseVowels(string s) {
    int head = 0, tail = s.length() - 1;
    char tmp;
    set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    while(head < tail){
        while(vowels.count(s[head]) == 0 && head < tail)
            head++;
        while(vowels.count(s[tail]) == 0 && head < tail)
            tail--;
        tmp = s[head];
        s[head++] = s[tail];
        s[tail--] = tmp;
    }
    return s;
}


int main(){
    string s = "hello";
    cout<<reverseVowels(s)<<endl;
}