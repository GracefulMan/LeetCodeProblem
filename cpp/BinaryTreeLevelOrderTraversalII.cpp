//
// Created by 马鸿英 on 2019/2/1.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

int height(TreeNode *root){
    if(!root) return 0;
    else return 1+height(root->left)+height(root->right);
}
void levelOrder(TreeNode *root,vector<int>&v,int level,int h){
    if(!root) return;
    if(level==h) {
        v.push_back(root->val);
    }
    levelOrder(root->left,v,level+1,h);
    levelOrder(root->right,v,level+1,h);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    int treeHeight = height(root);
    for(int i=treeHeight;i>=0;i--){
        vector<int> v;
        levelOrder(root,v,0,i);
        if (v.size()!=0) {
            res.push_back(v);
        }
    }
    return res;
}

