class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return -1e8;  // Return a very small value when out of bounds
        }
        
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        
        if (i == n - 1) {
            if (j1 == j2) {
                return dp[i][j1][j2] = grid[i][j1];  // Both robots on the same cell
            } else {
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];  // Robots on different cells
            }
        }
        
        int maxi = -1e8;
        
        for (int di = -1; di <= 1; di++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int ans;
                if (j1 == j2) {
                    ans = grid[i][j1] + helper(grid, i + 1, j1 + di, j2 + d2, dp);
                } else {
                    ans = grid[i][j1] + grid[i][j2] + helper(grid, i + 1, j1 + di, j2 + d2, dp);
                }
                maxi = max(maxi, ans);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (n == 0 || m == 0) return 0;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return helper(grid, 0, 0, m - 1, dp);
    }
};
