#include <vector>

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        for (int i = 0; i < n; i++) {  // Adjusted loop condition
            bool f = false;  // Moved inside the loop
            if(i+m>=n)
                break;
            for (int k = 0; k < m; k++) {  // Adjusted loop condition
                if (pattern[k] == 1) {
                    if (nums[i + k + 1] > nums[i + k]) continue;
                } else if (pattern[k] == 0) {
                    if (nums[i + k + 1] == nums[i + k]) continue;
                } else if (pattern[k] == -1) {
                    if (nums[i + k + 1] < nums[i + k]) continue;
                }

                f = true;
                break;
            }

            if (!f) {
                count++;
            }
        }

        return count;
    }
};
