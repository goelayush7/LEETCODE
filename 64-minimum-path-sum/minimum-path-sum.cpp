class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int down = INT_MAX;
                if(i+1<m){
                    down = grid[i][j] + dp[i+1][j];
                }
                int right = INT_MAX;
                if(j+1<n){
                    right = grid[i][j] + dp[i][j+1];
                }
                dp[i][j] = min(right,down);
            }
        }
        return dp[0][0];
    }
};