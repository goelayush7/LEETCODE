class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int n = nums.size();
        int i = 0;
        
        // Skip leading 0s
        while (i < n && nums[i] == 0) i++;
        if (i == n) return 0;  // all zeroes
        
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == 1) {
                ans = (ans * (j - i)) % mod;
                i = j;
            }
        }
        return ans;
    }
};
