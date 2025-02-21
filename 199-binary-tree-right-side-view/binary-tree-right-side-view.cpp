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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<pair<TreeNode*,int>>q;
        map<int,int>maps;
        q.push({root,0});
        vector<int>ans;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int row =front.second;
            maps[row] = node->val;
            if(node->left){
                q.push({node->left,row+1});
            }
            if(node->right){
                q.push({node->right,row+1});
            }
        }
        for(auto it : maps){
            ans.push_back(it.second);
        }
        return ans;

    }
};