//
// Created by 马鸿英 on 2020-04-14.
//


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned long int low = 1, high = n;
        unsigned long int mid;
        while(low <= high){
            if(mid - 1 >=1 &&isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;
            if(mid+1<=n &&!isBadVersion(mid) && isBadVersion(mid+1))
                return mid+1;
            mid = (low + high) / 2;
            if(isBadVersion(mid)){
                high=mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
