class Solution {
public:
    long long solve(int i,int f,int n,vector<int>&v,vector<vector<long long>>&dp) {
        if(i==n)
            return 0;
        if(dp[i][f]!=-1)
            return dp[i][f];
        long long a=0,b=0;
        if(f==0) {
            a=v[i]+solve(i+1,0,n,v,dp);
            b=-1*v[i]+solve(i+1,1,n,v,dp);
        } else {
            a=v[i]+solve(i+1,0,n,v,dp);
            return dp[i][f]=a;
        }
        return dp[i][f]=max(a,b);
    }
    long long maximumTotalCost(vector<int>& v) {
        int n = v.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        long long ans = v[0]+solve(1,0,n,v,dp);
        return ans;
    }
};