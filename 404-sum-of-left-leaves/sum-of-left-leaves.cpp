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
    int sum=0;
    int sumofleft(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL) sum = sum+root->left->val;
            sumofleft(root->left);
        }
        if(root->right){
            sumofleft(root->right);
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumofleft(root);
       
    }
};