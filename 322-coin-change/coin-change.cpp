class Solution {
public:
    int helper(vector<int>&coins,int amount ,int index,vector<vector<int>>&dp){
        if(index==coins.size() || amount<0){
            return 100000;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(amount==0){
            return dp[index][amount] = 0;
        }
        int take = 1+ helper(coins,amount-coins[index],index,dp);
        int nottake = helper(coins,amount,index+1,dp);
        return dp[index][amount] = min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));

        int ans = helper(coins,amount,0,dp);
        if(ans==100000)return -1;
        return ans;
    }
};