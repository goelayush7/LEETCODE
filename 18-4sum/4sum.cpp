class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::set<std::vector<int>> s;
        std::vector<std::vector<int>> v;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                      long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for (auto quadruplet : s) {
            v.push_back(quadruplet);
        }
        return v;
    }
};