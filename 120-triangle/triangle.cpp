class Solution {
public:
    int helper(vector<vector<int>>&triangle,int row,int col,int n,vector<vector<int>>&dp){
        if(row>=n){
            return 0;
        }
        if(dp[row][col]!=INT_MIN){
            return dp[row][col];
        }
        //taking ith index;
        int a = triangle[row][col] + helper(triangle,row+1,col,n,dp);
        //taking the ith+1 index

        int b = INT_MAX;
        if(row+1<n && col+1<triangle[row+1].size()){
            b = triangle[row][col] + helper(triangle,row+1,col+1,n,dp);
        }
        return dp[row][col] = min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return helper(triangle,0,0,triangle.size(),dp);
    }
};