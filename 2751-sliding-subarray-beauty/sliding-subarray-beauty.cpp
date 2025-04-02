class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> ms;
        int i = 0;
        int j = 0;
        vector<int> res;
        while (j < k) {
            if (nums[j] < 0) {
                ms.insert(nums[j]);
            }
            j++;
        }
        if (ms.size() < x)
            res.push_back(0);
        else
            res.push_back(*next(ms.begin(), x - 1));
        while (j < nums.size()) {
            if (nums[j] < 0) {
                ms.insert(nums[j]);
            }
            if (nums[i] < 0) {
                ms.erase(ms.find(nums[i]));
            }
            i++;
            if (ms.size() < x)
                res.push_back(0);
            else
                res.push_back(*next(ms.begin(), x - 1));
            j++;
        }
        return res;
    }
};