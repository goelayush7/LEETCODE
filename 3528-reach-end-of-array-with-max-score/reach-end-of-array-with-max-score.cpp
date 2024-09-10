class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        int start = 0;

        // Loop through the array
        for (int i = 0; i < n; i++) {
            if (i > start && nums[i] > nums[start]) {
                // Add the score for the current segment
                ans += static_cast<long long>(nums[start]) * (i - start);
                start = i; // Move the start pointer to the new maximum position
            }
        }

        if (ans == 0) {
            ans = static_cast<long long>((n - 1) * nums[0]);
            start = nums.size() - 1;
        }

        if (start != n - 1) {
            ans += static_cast<long long>(nums[start]) * ((n - 1) - start);
        }

        return ans;
    }
};
