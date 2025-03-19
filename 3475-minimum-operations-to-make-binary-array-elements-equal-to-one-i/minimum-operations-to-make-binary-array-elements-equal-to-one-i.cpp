class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && i + 2 < n) {
                for (int j = i; j < i + 3; j++) {
                    nums[j] = 1 - nums[j];  
                }
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }
        
        return count;
    }
};