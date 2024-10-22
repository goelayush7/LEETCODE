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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<long long>vect;
        vector<int>ans;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front==NULL){
                long long sum = 0;
                for(int i =0;i<ans.size();i++){
                    sum+=ans[i];
                }
                vect.push_back(sum);
                ans.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                ans.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        if(k-1>=vect.size())return -1;
        return vect[k-1];
    }
};