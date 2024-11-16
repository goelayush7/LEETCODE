class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i <= n - k; i++) {
            bool flag = true;
            int maxi = nums[i];
            
            for (int j = 1; j < k; j++) {
                if (nums[i + j] != nums[i + j - 1] + 1) {
                    flag = false;
                    break;
                }
                maxi = max(maxi, nums[i + j]);
            }
            
            if (!flag) {
                ans.push_back(-1);
            } else {
                ans.push_back(maxi);
            }
        }
        
        return ans;
    }
};