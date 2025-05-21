class Solution {
public:
    int dp[71][4901];  // max 70 rows, sum up to 4900
    int ans = INT_MAX;

    int helper(vector<vector<int>>& mat, int target, int row, int sum) {
        if (row == mat.size()) {
            return abs(sum - target);
        }

        if (dp[row][sum] != -1) return dp[row][sum];

        int res = INT_MAX;
        for (int val : mat[row]) {
            res = min(res, helper(mat, target, row + 1, sum + val));
            if (res == 0) break; // early exit if perfect match
        }

        return dp[row][sum] = res;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(mat, target, 0, 0);
    }
};
