//
// Created by 马鸿英 on 2020-04-14.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros++;
            else if(zeros>0) swap(nums[i], nums[i - zeros]);
        }
    }
};