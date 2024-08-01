class Solution {
public:
    int robber(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        //take 
        int take = nums[index] + robber(nums,index+2,dp);
        int nottake = robber(nums,index+1,dp);
        return dp[index] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> dp(nums.size(), -1);
        for(int i =0;i<nums.size();i++){
            maxi = max(maxi,robber(nums,i,dp));
        }
        return maxi;
    }
};