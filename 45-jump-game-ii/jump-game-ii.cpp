class Solution {
public:
    long long helper(vector<int>& nums, int index, vector<int>& dp) {
        if (index == nums.size() - 1) {
            return 0;
        }
        if (index >= nums.size()) {
            return INT_MAX;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        
        long long int count = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            count = min(count, 1 + helper(nums, index + i, dp));
        }
        return dp[index] = count;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // Initialize DP array with -1
        return helper(nums, 0, dp);
    }
};
