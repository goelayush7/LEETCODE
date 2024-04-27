class Solution {
public:
    int solve(std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& grid, int row, int prevcol) {
        int n = grid.size();
        if (row == n - 1) {
            int temp = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (i != prevcol) {
                    temp = std::min(temp, grid[row][i]);
                }
            }
            return temp;
        }
        if(dp[row][prevcol]!=-1)return dp[row][prevcol];
        int mini = INT_MAX; // Initialize mini to INT_MAX

        for (int i = 0; i < n; i++) {
            if (i != prevcol) {
                int minii = grid[row][i] + solve(dp, grid, row + 1, i);
                mini = std::min(minii, mini);
            }
        }
        return dp[row][prevcol] = mini;
    }

    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX; // Initialize ans to INT_MAX
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
        if(n==1){
            return grid[0][0];
        }
        for (int i = 0; i < n; i++) {
            ans = std::min(solve(dp, grid, 0, i), ans);
        }
        return ans;
    }
};