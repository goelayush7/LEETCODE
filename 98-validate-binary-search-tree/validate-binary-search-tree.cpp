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
    long long findmin(TreeNode* root){
        if(root==NULL)return 1000000000000;
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    long long findmax(TreeNode* root){
        if(root==NULL)return -1000000000000;
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    bool check(TreeNode* root){
        if(root==NULL)return true;
        if(root->val<=findmax(root->left) || root->val>=findmin(root->right)){
            return false;
        }
        return check(root->left) && check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)return true;
        return check(root);
    }
};