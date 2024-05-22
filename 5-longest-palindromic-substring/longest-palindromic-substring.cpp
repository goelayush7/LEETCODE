class Solution {
public:
    int dp[1001][1001]; // Adjusted to a smaller size to avoid memory issues, change if needed

    bool solve(string &s, int start, int end) {
        if (start >= end)
            return true;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (s[start] == s[end])
            return dp[start][end] = solve(s, start + 1, end - 1);
        else
            return dp[start][end] = false;
    }

    string longestPalindrome(string s) {
        int maxi = 0;
        memset(dp, -1, sizeof(dp));
        int startingIndex = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxi) {
                        startingIndex = i;
                        maxi = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startingIndex, maxi);
    }
};
