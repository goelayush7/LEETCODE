class Solution {
public:
    int countInRange(vector<int>& nums, int startIdx, int low, int high) {
        // find first index >= low
        int l = startIdx, r = nums.size() - 1, leftIdx = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= low) {
                leftIdx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // find last index <= high
        l = startIdx, r = nums.size() - 1;
        int rightIdx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= high) {
                rightIdx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (leftIdx == nums.size() || rightIdx == -1 || leftIdx > rightIdx) 
            return 0;
        return rightIdx - leftIdx + 1;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i];
            int high = upper - nums[i];
            ans += countInRange(nums, i + 1, low, high); // only count j > i
        }
        return ans;
    }
};
