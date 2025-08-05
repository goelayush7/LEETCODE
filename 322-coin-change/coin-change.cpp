class Solution {
public:
    int helper(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        int n = coins.size();
        if(index==n || amount<0){
            return 100000;
        }
        if(amount==0){
            return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int take = 1+(helper(coins,amount-coins[index],index,dp));
        take = min(take,helper(coins,amount,index+1,dp));
        return dp[index][amount] = take;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = helper(coins,amount,0,dp);
        return ans==100000 ? -1 : ans;
    }
};