#include <iostream>
#include <string>
#include <map>
using namespace std;

string getHint(string secret, string guess) {
    int sec[10]={0}, gue[10] = {0};
    int bulls = 0, cows = 0;
    for(int i =0 ; i < secret.size(); i++){
        if(secret[i] == guess[i]) bulls++;
        sec[secret[i] - '0']++;
        gue[guess[i] - '0']++;
    }
    for(int i=0;i<10;i++){
        cows += min(sec[i], gue[i]);
    }
    cows -= bulls;
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main(){
    cout<<getHint("1807","7810")<<endl;
    cout<<getHint("1123","0111")<<endl;
}