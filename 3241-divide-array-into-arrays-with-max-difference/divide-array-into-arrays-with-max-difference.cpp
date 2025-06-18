class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vect;
        int j = 2;
        for (int i = 0; i <= nums.size() - 3; i += 3) {
            if ((nums[j] - nums[i]) > k)
                return {};
            j += 3;
        }
        vector<int> temp;

        for (auto it : nums) {
            temp.push_back(it);
            if (temp.size() == 3) {
                vect.push_back(temp);
                temp.clear();
            }
        }
        return vect;
    }
};