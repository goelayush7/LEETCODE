class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i + 1;
                break;
            }
        }
        
        vector<int> ans;
        for (int i = pivot; i < n; i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < pivot; i++) {
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            if (ans[i] > ans[i + 1]) {
                return false;
            }
        }
        return true;
    }
};