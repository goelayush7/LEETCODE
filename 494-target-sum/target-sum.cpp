class Solution {
public:
    int helper(vector<int>&nums,int target,int index,vector<vector<int>>&dp){
        if(index==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        if(dp[target+1000][index]!=-1)return dp[target+1000][index];
        //add
        int add = helper(nums,target-nums[index],index+1,dp);
        int minus = helper(nums,target+nums[index],index+1,dp);
        return dp[target+1000][index] = add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(3000,vector<int>(n+1,-1));
        return helper(nums,target,0,dp);
    }
};