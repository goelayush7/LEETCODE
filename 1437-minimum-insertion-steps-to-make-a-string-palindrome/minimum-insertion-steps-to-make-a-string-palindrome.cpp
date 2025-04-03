class Solution {
public:
    int helper(string &s,int start,int end,vector<vector<int>>&dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        //if both the ends are equal then no insertion is needed
        int equal = 1000;
        if(s[start]==s[end]){
            equal = helper(s,start+1,end-1,dp);
        }
        int notequal = 1+min(helper(s,start,end-1,dp),helper(s,start+1,end,dp));
        return dp[start][end] = min(equal,notequal);
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1,dp);
    }
};