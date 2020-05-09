//
// my explanation to my algorithm:
// https://leetcode.com/problems/nim-game/discuss/587179/100100-two-line-solution-with-a-detailed-mathematical-proof
//
#include <iostream>
using namespace std;
bool canWinNim(int n) {
    if (n<=3) return true;
    bool *data = new bool [n];
    for(int i=0;i<3;i++) {
        data[i] = true;
    }
    for(int i=3;i<n;i++){
        data[i] = !data[i-1] || !data[i-2] || !data[i-3];

    }
    return data[n-1];
}

bool canWinNim2(int n){
    bool  a[] = {true, true, true, false};
    return a[(n - 1) % 4];
}
bool canWinNim3(int n){
    if(n<=3) return true;
    else return !(canWinNim3(n-1) && canWinNim3(n-2) && canWinNim3(n-3));
}


int main(){
    for(int i=0;i<100;i++) {
        cout<<canWinNim2(i)<<'\t'<<canWinNim3(i)<<endl;

    }
}