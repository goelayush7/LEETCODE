class Solution {
public:
    bool helper(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
        if(index==nums.size()-1){
            if(target==nums[index]){
                return dp[index][target] = true;
            }
            return dp[index][target] = false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int take = false;
        if(nums[index]<=target){
            take = helper(nums,index+1,target-nums[index],dp);
        }
        int nottake = helper(nums,index+1,target,dp);
        return dp[index][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto& it : nums){
            target+=it;
        }
        if(target%2!=0)return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>((target/2)+1,-1));
        return helper(nums,0,target/2,dp);
    }
};