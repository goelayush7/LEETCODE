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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        vector<int>temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL){
                int me = *max_element(temp.begin(),temp.end());
                ans.push_back(me);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;

    }
};