class Solution {
public:
    long long helper(vector<vector<int>>&que,int index,vector<long long>&dp){
        if(index>=que.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //take that question
        long long take = que[index][0] + helper(que,index+que[index][1]+1,dp);
        //not solve
        long long nottake = helper(que,index+1,dp);
        return dp[index] = max(take,nottake);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,-1);
        return helper(questions,0,dp);
    }
};