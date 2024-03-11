#include <string>

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr2(128, 0); 
        for (int i = 0; i < s.size(); i++) {
            arr2[s[i]]++;
        }

        int i = 0;
        string ans = "";

        while (i < order.size()) {
            if (arr2[order[i]] != 0) {
                ans += order[i];
                arr2[order[i]]--;
            } else {
                i++;
            }
        }

        for (int i = 0; i < 128; i++) { 
            while (arr2[i] > 0) {
                ans += char(i);
                arr2[i]--;
            }
        }

        return ans;
    }
};
