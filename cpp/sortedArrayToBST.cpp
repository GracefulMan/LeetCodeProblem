//
// Created by 马鸿英 on 2019/3/3.
//
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int size = nums.size();
    if (size==0) return NULL;
    int mid = size/2;
    vector<int> left,right;
    for(int i=0;i<mid;i++) left.push_back(nums[i]);
    for(int i= mid+1;i<size;i++) right.push_back(nums[i]);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}
int main(){
    vector<int>test ={-10,-3,0,5,9};
    sortedArrayToBST(test);
}