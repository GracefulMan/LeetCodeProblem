class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        while(num){
            if(num == 1) return true;
            if(num % 4 != 0) return false;
            num = num >> 2;

        }
        return true;
    }
};
