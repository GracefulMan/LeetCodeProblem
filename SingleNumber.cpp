//
// Created by 马鸿英 on 2019/3/5.
//

#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    for(int i=1;i<nums.size();i++){
        nums[0]^=nums[i];
    }
    return nums[0];
}
int main(){
    vector<int>a={1,1,2};
    cout<<singleNumber(a);
}
