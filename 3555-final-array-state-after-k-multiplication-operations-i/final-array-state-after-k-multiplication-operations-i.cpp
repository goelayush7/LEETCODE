#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        int i = 0;
        while (i < k) {
            int mini = INT_MAX;
            int index = -1;
            for (int j = 0; j < n; j++) {
                if (nums[j] < mini) {
                    mini = nums[j];
                    index = j;
                }
            }
            if (index != -1) {
                nums[index] *= multiplier;
            }
            i++;
        }
        return nums;
    }
};
