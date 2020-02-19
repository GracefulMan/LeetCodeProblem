//
// Created by 马鸿英 on 2019/3/5.
//
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

int minDepth(TreeNode* root) {
    if(!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if(left==0&&right==0) return 1;
    if(left==0) return right +1;
    if(right==0) return left +1;
    return min(left,right)+1;
}
