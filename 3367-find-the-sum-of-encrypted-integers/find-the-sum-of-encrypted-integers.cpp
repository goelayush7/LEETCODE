#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        vector<string> nums1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int maxi = 0;
            int s = 0;
            while (num > 0) {
                maxi = max(maxi, num % 10);
                num = num / 10;
                s++;
            }
            string f = to_string(maxi);
            string encryptedInt = "";
            for (int j = 0; j < s; j++) {
                encryptedInt += f;
            }
            nums1.push_back(encryptedInt);
        }
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            ans += stoi(nums1[i]);
        }
        return ans;
    }
};
