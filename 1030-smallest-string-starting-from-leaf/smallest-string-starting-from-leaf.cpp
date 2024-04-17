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
    string ans = "";
    void smallest(TreeNode* root,string path){
        path+=root->val+'a';
        if(!root->left && !root->right){
            reverse(path.begin(),path.end());
            if(ans.empty() || ans>path){
                ans = path;
            }
            reverse(path.begin(),path.end());
        }
        if(root->left)smallest(root->left,path);
        if(root->right)smallest(root->right,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        smallest(root,path);
        return ans;
    }
};