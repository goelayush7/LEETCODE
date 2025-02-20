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
    int maxheight(TreeNode* root){
        if(root==NULL)return 0;
        int right = 1;
        if(root->right){
            right = 1+maxheight(root->right);
        }
        int left = 1;
        if(root->left){
            left = 1+maxheight(root->left);
        }
        return max(right,left);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        if(abs(maxheight(root->left)-maxheight(root->right))>1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};