//
// Created by 马鸿英 on 2019/1/31.
//
#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size()<=1){
        return nums.size();
    }
   int i=0,j=0;
    while(j<nums.size()){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
        j++;
    }
    return i+1;

}
int main(){
    vector<int> nums={1,1,2,2,3,4,4,5,6};
    int length = removeDuplicates(nums);
    for(int i=0;i<length;i++){
        cout<<nums[i]<<'\t';
    }
}