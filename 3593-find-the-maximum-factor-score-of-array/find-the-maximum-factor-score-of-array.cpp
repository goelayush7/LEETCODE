class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long ans = 0;
        long long lcm1 = nums[0];
        long long gcd1 = nums[0];
        for (int i = 1; i < nums.size(); i++) { /// when all numbers are taken
            lcm1 = lcm(lcm1, nums[i]);
            gcd1 = gcd(gcd1, nums[i]);
        }
        ans = max(ans, lcm1 * gcd1);

        for (int i = 0; i < nums.size(); i++) {
            lcm1 = -1;
            gcd1 = -1;
            for (int j = 0; j < nums.size(); j++) {
                if(i==j)continue;
                if (lcm1 == -1) {
                    lcm1 = nums[j];
                    gcd1 = nums[j];
                } else 
                     {
                        lcm1 = lcm(lcm1, nums[j]);
                        gcd1 = gcd(gcd1, nums[j]);
                    }
            }
            ans = max(ans, lcm1 * gcd1);
        }
        return ans;
    }
};