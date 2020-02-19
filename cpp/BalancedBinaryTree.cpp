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
int height(TreeNode *root){
    if(!root) return 0;
    else return 1+max(height(root->left),height(root->right));
}
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    int left = height(root->left);
    int right = height(root->right);
    if(left-right>1||right-left>1) return false;
    return isBalanced(root->left)&&isBalanced(root->right);
}
