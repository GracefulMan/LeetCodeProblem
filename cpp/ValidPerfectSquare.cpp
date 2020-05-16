class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int tail = num % 10;
        if(tail==2||tail==3||tail==7||tail==8) return false;
        long x_k = min(num / 2,46340);
        long power2 = x_k * x_k;
        while(power2 > num){
            x_k = (x_k + num / x_k) / 2;
            power2 = x_k * x_k;
        }
        return x_k * x_k == num;
    }
};