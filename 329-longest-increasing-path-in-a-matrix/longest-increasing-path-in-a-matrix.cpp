class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int n = matrix.size(), m = matrix[0].size();
        int longest = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int ni = i + drow[d];
            int nj = j + dcol[d];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                longest = max(longest, 1 + dfs(ni, nj, matrix, dp));
            }
        }

        return dp[i][j] = longest;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, dfs(i, j, matrix, dp));
            }
        }

        return result;
    }
};
