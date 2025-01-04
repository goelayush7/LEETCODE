class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mini = -1, maxi = -1;

        // Find the first occurrence of target
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                mini = mid; // Update mini
                end = mid - 1; // Search in the left half
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Find the last occurrence of target
        start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                maxi = mid; // Update maxi
                start = mid + 1; // Search in the right half
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return {mini, maxi};
    }
};
