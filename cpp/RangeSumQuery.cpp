#include <vector>
#include <iostream>
using namespace std;
/*
 * my explanation to my algorithm:
 * https://leetcode.com/problems/range-sum-query-immutable/discuss/621714/c%2B%2B-beats-99.20-O(N)-with-detailed-explanation
 */
class NumArray {
private:
    int *data;
public:
    NumArray(vector<int>& nums) {
        if(nums.size()!=0) {
            data = new int[nums.size() + 1];
            data[0] = 0;
            for (int i = 0; i < nums.size(); i++) {
                data[i + 1] = data[i] + nums[i];
            }
        }
    }
    int sumRange(int i, int j) {
        return data[j+1] - data[i];

    }
};
int main(){
    vector<int> nums={-2,0,3,-5,2,-1};
    NumArray *obj = new NumArray(nums);
    cout<<obj->sumRange(0,2)<<endl;
    cout<<obj->sumRange(2,5)<<endl;
    cout<<obj->sumRange(0,5);
}