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

bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(!root->left&&!root->right) return sum==root->val;
    return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
}
