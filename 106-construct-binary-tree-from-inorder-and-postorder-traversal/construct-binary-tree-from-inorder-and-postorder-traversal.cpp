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
    int idx = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = postorder.size()-1;
        return createtree(inorder,postorder,0,postorder.size()-1);
    }
    TreeNode* createtree(vector<int>&inorder,vector<int>&postorder,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[idx--]);
        int pos;
        for(int i = start;i<=end;i++){
            if(node->val==inorder[i]){
                pos=i;
                break;
            }
        }
        node->right = createtree(inorder,postorder,pos+1,end);
        node->left = createtree(inorder,postorder,start,pos-1);
        return node;
    }

};