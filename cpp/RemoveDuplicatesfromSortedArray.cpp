#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
        if (*it == val) nums.erase(it);
        else it++;
        return nums.size();
    }
}
int main(){
    vector<int> nums={1,1,2,2,3,4,4,5,6};
    int length = removeElement(nums,6);
    for(int i=0;i<length;i++){
        cout<<nums[i]<<'\t';
    }
}