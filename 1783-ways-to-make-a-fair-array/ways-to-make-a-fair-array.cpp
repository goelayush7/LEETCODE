class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int totaleven = 0;
        int totalodd = 0;

        // total sums at original parities
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                totaleven += nums[i];
            } else {
                totalodd += nums[i];
            }
        }

        int count = 0;
        int cumeven = 0;
        int cumodd = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool isfair;
            if (i % 2 == 0) {
                isfair = (cumeven + (totalodd - cumodd) ==
                          cumodd + (totaleven - cumeven - nums[i]));
                cumeven += nums[i];
            } else {
                isfair = (cumeven + (totalodd - cumodd - nums[i]) ==
                          cumodd + (totaleven - cumeven));
                cumodd += nums[i];
            }
            if (isfair)
                count++;
        }

        return count;
    }
};
