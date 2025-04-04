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
    pair<int,TreeNode*> helper(TreeNode* root){
        if(root==NULL){
            return {0,NULL};
        }
        auto lca1 = helper(root->left);
        auto lca2 = helper(root->right);
        if(lca1.first==lca2.first){
            return {lca1.first+1,root};
        }
        else if(lca1.first>lca2.first){
            return {lca1.first+1,lca1.second};
        }
        else return {lca2.first+1,lca2.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root){
        return helper(root).second;
        
    }
};