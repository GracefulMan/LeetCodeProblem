#include <iostream>
#include <map>
#include <string>
using namespace std;


//exceed time limit!!!!
bool wordPattern(string pattern, string str) {
    map<char, string> res_map;
    map<string, char> res2_map;
    int start =0;
    int length=0;
    string tmp ;
    //check whitespace nums.
    int nums = 0;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]!=' ' && str[i+1]==' ')
            nums++;
    }
    if(nums+1 != pattern.size()) return false;


    for(int i=0;i<pattern.size();i++){
        length = 0;
        while(str[length]!=' ') length++;
        tmp = str.substr(start, length);
        if(res_map.find(pattern[i])!= res_map.end()){
            if(tmp != res_map[pattern[i]]){
                return false;
            }
        } else{
            res_map[pattern[i]]=tmp;
        }

        if(res2_map.find(tmp)!= res2_map.end()){
            if(pattern[i] != res2_map[tmp]){
                return false;
            }
        } else{
            res2_map[tmp]=pattern[i];
        }

        while(str[length]==' ') length++;
        start += length;
    }
    return true;


}
int main (){
    string pattern = "a";
    string str = "a";
    cout<<wordPattern(pattern, str)<<endl;

}