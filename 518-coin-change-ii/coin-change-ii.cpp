class Solution {
public:
    int helper(int amount,vector<int>&coins,int index,vector<vector<int>>&dp){
        if(index==coins.size()-1){
            return dp[index][amount] = amount%coins[index]==0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int nottake = helper(amount,coins,index+1,dp);
        int take = 0;
        if(coins[index]<=amount){
            take = helper(amount-coins[index],coins,index,dp);
        }
        return dp[index][amount] = take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return helper(amount,coins,0,dp);
    }
};