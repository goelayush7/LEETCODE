class Solution {
public:
    int helper(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        int m = matrix.size();
        int n = matrix[0].size();
        if(row==m){
            return 0;
        }
        if(dp[row][col]!=-10000000)return dp[row][col];
        int left = INT_MAX;
        if(col-1>=0){
            left = matrix[row][col-1] + helper(matrix,row+1,col-1,dp);
        }
        left = min(left,matrix[row][col] + helper(matrix,row+1,col,dp));
        if(col+1<n){
            left = min(left,matrix[row][col+1] + helper(matrix,row+1,col+1,dp));
        }
        return dp[row][col] = left;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = INT_MAX;
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-10000000));
        for(int i = 0;i<matrix.size();i++){
            sum = min(sum,helper(matrix,0,i,dp));
        }
        return sum;
    }
};