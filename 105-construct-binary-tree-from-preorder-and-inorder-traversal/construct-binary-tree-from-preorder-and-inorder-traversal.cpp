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
    int preind = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createtree(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode* createtree(vector<int>preorder,vector<int>&inorder,int start,int end){
        if(start>end){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preind++]);
        int pos = -1;
        for(int j =start;j<=end;j++){
            if(inorder[j]==node->val){
                pos= j;
                break;
            }
        }
        node->left = createtree(preorder,inorder,start,pos-1);
        node->right = createtree(preorder,inorder,pos+1,end);
        return node;

    }
};