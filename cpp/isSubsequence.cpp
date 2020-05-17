#include <iostream>
#include <string>
using namespace std;
bool isSubsequence(string s, string t) {
    if(s.length()==0) return true;
    else if(s.length() != 0 && t.length() ==0 ) return false;
    else{
        char tmp = s[0];
        int index = -1;
        for(int i=0;i<t.length();i++){
            if(t[i] == tmp){
                index = i;
                break;
            }
        }
        if(index == -1) return false;
        s.assign(s,1, string::npos);
        cout<<s<<'\t';
        cout<<index<<'\t';
        t.assign(t,index+1, string::npos);
        cout<<t<<'\t';
        cout<<endl;
        return isSubsequence(s, t);
    }
}


int main(){
    cout<<isSubsequence("aaaaaaa","aaaaabc");
}