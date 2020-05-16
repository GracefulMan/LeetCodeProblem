/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long high = n, low = 1;
        while(low <= high){
            long mid = (low + high) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};