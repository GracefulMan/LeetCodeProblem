class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> list1(nums1.begin(),nums1.end());
        set<int> list2(nums2.begin(), nums2.end());
        set<int>res;
        set_intersection(list1.begin(),list1.end(),list2.begin(),list2.end(),inserter(res, res.begin()));
        nums1.assign(res.begin(), res.end());
        return nums1;
    }
};