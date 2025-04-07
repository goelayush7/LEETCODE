class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vect;

        for (int i = 0; i < nums.size(); i++) {
            int original = nums[i];
            int mapped = 0;
            int place = 1;

            if (original == 0) {
                mapped = mapping[0];
            } else {
                int temp = original;
                vector<int> digits;
                while (temp > 0) {
                    digits.push_back(temp % 10);
                    temp /= 10;
                }
                reverse(digits.begin(), digits.end());

                for (int d : digits) {
                    mapped = mapped * 10 + mapping[d];
                }
            }

            vect.push_back({mapped, i});
        }

        sort(vect.begin(), vect.end());

        vector<int> ans;
        for (auto& [mapped, idx] : vect) {
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};
