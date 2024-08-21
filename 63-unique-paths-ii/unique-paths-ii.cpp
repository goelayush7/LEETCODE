class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(grid[i][j]==1){
            return dp[i][j]= 0;
        }
        if(i==n-1 && j==m-1){
            return dp[i][j]=1;
        }
        int a = helper(grid,i+1,j,n,m,dp);
        int b = helper(grid,i,j+1,n,m,dp);
        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,0,0,n,m,dp);
    }
};