//
// Created by 马鸿英 on 2019/2/1.
//
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    else return max(maxDepth(root->left),maxDepth(root->right))+1;
}