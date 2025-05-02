class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> maps;
        maps[0] = -1;  // handle the case where the subarray starts from index 0
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = k == 0 ? sum : sum % k;

            if (maps.find(rem) != maps.end()) {
                if (i - maps[rem] > 1)
                    return true;
            } else {
                maps[rem] = i;  // only insert if not present
            }
        }
        return false;
    }
};
