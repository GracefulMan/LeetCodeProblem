//
// Created by 马鸿英 on 2019/1/31.
//

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    if(s.length()==0)
        return true;
    if(s.length()==1)
        return false;
    stack<char>my;
    for(int i =0 ; i < s.length(); i++){
        char temp =s[i];
        if(temp=='{'||temp=='('||temp=='['){
            my.push(temp);
        } else{
            if(my.empty()){
                return false;
            } else{
                char res = my.top();
                my.pop();
                if((temp==']'&&res!='[')||(temp==')'&&res!='(')||(temp=='}'&&res!='{'))
                    return false;
            }
        }
    }
    return my.empty();
}
int main (){
    cout<<isValid( "()[]{}")<<endl;
}