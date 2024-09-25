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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        vector<vector<int>>out;
        vector<int>ans;
        q.push(root);
        q.push(NULL);
        int d =1;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front==NULL){
                if(d==0){
                    reverse(ans.begin(),ans.end());
                    out.push_back(ans);
                    d=1;
                }
                else if(d==1){
                    out.push_back(ans);
                    d=0;
                }
                ans.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                ans.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
        return out;
    }
};