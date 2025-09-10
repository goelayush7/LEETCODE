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
    void inorder(TreeNode* root,vector<int>&inor){
        if(root==NULL)return ;
        inorder(root->left,inor);
        inor.push_back(root->val);
        inorder(root->right,inor);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>sorted;
        inorder(root,sorted);
        vector<vector<int>>ans;
        for(auto it : queries){
            int start = 0;
            int end = sorted.size()-1;
            int mini = INT_MIN;
            int maxi = INT_MAX;
            //find min;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(sorted[mid]<=it){
                    mini = max(mini,sorted[mid]);
                    start = mid+1;
                }
                else end = mid-1;
            }
            start = 0;
            end = sorted.size()-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(sorted[mid]>=it){
                    maxi = min(maxi,sorted[mid]);
                    end = mid-1;
                }
                else start = mid+1;
            }
            if(mini==INT_MIN)mini=-1;
            if(maxi==INT_MAX)maxi=-1;
            ans.push_back({mini,maxi});
        }
        return ans;
    }
};