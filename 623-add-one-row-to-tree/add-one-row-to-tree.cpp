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
    void addepth(TreeNode* root,int val,int depth,int cur){
        if(depth==cur){
            TreeNode* newnodeleft = new TreeNode(val);
            TreeNode* newnoderight = new TreeNode(val);
            TreeNode* rootleft = root->left;
            TreeNode* rootright = root->right;
            root->left = newnodeleft;
            newnodeleft->left = rootleft;
            root->right = newnoderight;
            newnoderight->right = rootright;
            return;
        }
        if(root->left){
            addepth(root->left,val,depth,cur+1);
        }
        if(root->right){
            addepth(root->right,val,depth,cur+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int cur=1;
        if(depth==1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        addepth(root,val,depth-1,cur);
        return root;
    }
};