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
class Solution {
public:
    bool check(TreeNode* lefttree,TreeNode* righttree){
        if(lefttree==NULL && righttree==NULL)return true;
        if(lefttree==NULL || righttree==NULL)return false;
        if(lefttree->val!=righttree->val)return false;
        return check(lefttree->left,righttree->right) && check(lefttree->right,righttree->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return check(root->left,root->right);

    }
};