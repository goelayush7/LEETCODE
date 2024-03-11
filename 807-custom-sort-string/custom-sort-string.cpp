#include <string>

class Solution {
public:
    string customSortString(string order, string s) {
        // Use 'vector' instead of 'int' arrays
        vector<int> arr1(26, 0);
        vector<int> arr2(128, 0); // Increase array size to cover ASCII characters

        // Count occurrences of characters in 'order'
        for (int i = 0; i < order.size(); i++) {
            arr1[order[i] - 'a']++;
        }

        // Count occurrences of characters in 's'
        for (int i = 0; i < s.size(); i++) {
            arr2[s[i]]++;
        }

        int i = 0;
        int j = 0;
        string ans = "";

        // Process characters in 'order'
        while (i < order.size()) {
            if (arr2[order[i]] != 0) {
                ans += order[i];
                arr2[order[i]]--;
            } else {
                i++;
            }
        }

        // Process remaining characters in 's'
        for (int i = 0; i < 128; i++) { // Iterate over all ASCII characters
            while (arr2[i] > 0) {
                ans += char(i);
                arr2[i]--;
            }
        }

        return ans;
    }
};
