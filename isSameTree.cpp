//
// Created by 马鸿英 on 2019/1/31.
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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL&&q==NULL) return true;
    if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)||((p!=NULL&&q!=NULL)&&(p->val!=q->val)))
        return false;
    bool leftRes=true,rightRes=true;
    if(p->left)  leftRes = isSameTree(p->left,q->left);
    if(p->right)  rightRes = isSameTree(p->right,q->right);
    return leftRes&&rightRes;
}
