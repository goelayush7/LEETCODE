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
    TreeNode* helper(vector<int>& nums, int start,int end){
        if(start>end){
            return NULL;
        }
        int idx = -1;
        int maxi = -1;
        for(int i = start;i<=end;i++){
            if(maxi<nums[i]){
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = helper(nums,start,idx-1);
        root->right= helper(nums,idx+1,end);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};