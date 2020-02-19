//
// Created by 马鸿英 on 2019/1/31.
//
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL&&q==NULL) return true;
    else if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)||(p->val!=q->val))
        return false;
    else return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}
