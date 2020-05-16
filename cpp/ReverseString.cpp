class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int length = s.size();
        for(int i=0;i < length / 2;i++){
            tmp = s[i];
            s[i] = s[length - i - 1];
            s[length - i - 1] = tmp;
        }
    }
};