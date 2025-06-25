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
    int ans = INT_MIN;
    int value(TreeNode* root){
        if(root==nullptr)return 0;
        int left = max(value(root->left),0);
        int right = max(value(root->right),0);
        int val = root->val+left+right;
        ans = max(ans,val);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return root->val;
        if(root==NULL)return 0;
        value(root);
        return ans;
    }
};