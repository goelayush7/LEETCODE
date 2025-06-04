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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int a = 0;
        if(root->left)a=height(root->left);

        int b = 0;
        if(root->right) b = height(root->right);
        return max(a,b)+1;
    }


    bool helper(TreeNode* root){
        if(root==NULL)return true;
        int left = 0;
        int right = 0;
        if(root->left)left = height(root->left);
        if(root->right) right = height(root->right);

        return (abs(left-right)<=1) && helper(root->left) && helper(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};