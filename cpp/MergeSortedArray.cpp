//
// Created by 马鸿英 on 2019/1/31.
//

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res;
    int i=0,j=0;
    while(i<m&&j<n){
        if(nums1[i]<=nums2[j]) res.push_back(nums1[i++]);
        else res.push_back(nums2[j++]);
    }
    while(i<m) res.push_back(nums1[i++]);
    while(j<n) res.push_back(nums2[j++]);
    nums1=res;
}
int main(){
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    int m=1,n=0;
    merge(nums1,m,nums2,n);
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<'\t';
    }

}