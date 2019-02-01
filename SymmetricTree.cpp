//
// Created by 马鸿英 on 2019/2/1.
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
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    stack<TreeNode *>leftStack;
    stack<TreeNode *>rightStack;
    if( (root->left&&!root->right) || (!root->left&&root->right) ) return false;
    leftStack.push(root->left);
    rightStack.push(root->right);
    while(!leftStack.empty()&&!rightStack.empty()){
        TreeNode *leftNode = leftStack.top();
        leftStack.pop();
        TreeNode *rightNode = rightStack.top();
        rightStack.pop();
        if(!leftNode&&!rightNode) return true;
        if((leftNode->left&&!rightNode->right)||(leftNode->right&&!rightNode->left))
            return false;
        if((!leftNode->left&&rightNode->right)||(!leftNode->right&&rightNode->left))
            return false;
        if(leftNode->val!=rightNode->val) return false;
        if(leftNode->left){
            leftStack.push(leftNode->left);
            rightStack.push(rightNode->right);
        }
        if(leftNode->right){
            leftStack.push(leftNode->right);
            rightStack.push(rightNode->left);
        }
    }
    return leftStack.empty()&&rightStack.empty();
}
bool res = true;
void check(TreeNode *t1,TreeNode *t2){
    if((!t1&&t2)||(t1&&!t2)) res = false;
    if(t1&&t2){
        if(t1->val!=t2->val) res = false;
        check(t1->left,t2->right);
        check(t1->right,t2->left);
    }
}
bool isSymmetric2(TreeNode* root) {
    if(!root) return true;
    check(root->left,root->right);
    return res;
}