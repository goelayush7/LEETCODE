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
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>out;
        vector<int>temp;
        bool flag = true;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                if(flag==true){
                    out.push_back(temp);
                    flag = !flag;
                }
                else if(!flag){
                    reverse(temp.begin(),temp.end());
                    out.push_back(temp);
                    flag=!flag;
                }
                temp.clear();
            }
            else{
                temp.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return out;
    }
};