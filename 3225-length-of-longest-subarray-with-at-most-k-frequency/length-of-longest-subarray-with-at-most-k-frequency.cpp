class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i = 0, maxi = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            
            // Shrink window if any number appears more than k times
            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};
