/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


#include <stack>
#include <iostream>
using namespace std;


//recursive solution.
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int val = 0;
        if(root){
            if(root->left &&!root->left->left && !root->left->right)
                val += root->left->val;
            else {
                val += sumOfLeftLeaves(root->left);
            }
            if(root->right)
                val += sumOfLeftLeaves(root->right);
        }
        return val;
    }
};


