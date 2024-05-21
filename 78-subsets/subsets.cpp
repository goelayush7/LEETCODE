class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&cur,int i){
        ans.push_back(cur);
        for(int j = i ; j<nums.size();j++){
            cur.push_back(nums[j]);
            helper(nums,ans,cur,j+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(nums,ans,curr,0);
        return ans;
    }
};