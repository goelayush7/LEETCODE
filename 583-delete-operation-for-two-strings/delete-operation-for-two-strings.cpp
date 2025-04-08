class Solution {
public:
    vector<vector<int>> dp;

    int helper(string& word1, string& word2, int i, int j) {
        if (i == word1.length()) return word2.length() - j;  // delete rest of word2
        if (j == word2.length()) return word1.length() - i;  // delete rest of word1

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = helper(word1, word2, i + 1, j + 1);
        } else {
            int deleteFromWord1 = 1 + helper(word1, word2, i + 1, j);
            int deleteFromWord2 = 1 + helper(word1, word2, i, j + 1);
            return dp[i][j] = min(deleteFromWord1, deleteFromWord2);
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, 0, 0);
    }
};
