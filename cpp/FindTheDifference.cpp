#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int nums[26] = {0};
        for(int i=0;i<t.length();i++){
            nums[t[i] - 'a'] ++;
        }
        for(int i=0;i<s.length();i++){
            nums[s[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(nums[i] != 0){
                return i+'a';
            }
        }
        return NULL;
    }
};