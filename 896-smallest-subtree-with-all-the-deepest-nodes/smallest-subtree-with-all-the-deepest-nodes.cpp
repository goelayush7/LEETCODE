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
    int maxdepth(TreeNode* root){
        if(root==NULL)return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        return max(left,right)+1;
    }
    TreeNode* helper(TreeNode* root,int depth,int maxdep){
        if(root==NULL)return nullptr;
        if(depth==maxdep){
            return root;
        }
        TreeNode* lefttree = helper(root->left,depth+1,maxdep);
        TreeNode* righttree = helper(root->right,depth+1,maxdep);
        if(lefttree!=NULL && righttree!=NULL){
            return root;
        }
        if(lefttree!=NULL)return lefttree;
        else return righttree;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxdep = maxdepth(root);
        return helper(root,1,maxdep);
    }
};