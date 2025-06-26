class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        long long value = 0;
        int count = 0;
        long long power = 1;
        int i = n - 1;

        while (i >= 0) {
            if (s[i] == '1') {
                if (power > k) {
                    break;  // Further '1' will always exceed k
                }
                if (value + power <= k) {
                    value += power;
                    count++;
                } else {
                    break;
                }
            } else {
                count++;
            }

            // Only double power if within safe range
            if (power <= k) {
                power *= 2;
            }
            i--;
        }

        // Remaining '0's can always be added
        while (i >= 0) {
            if (s[i] == '0') count++;
            i--;
        }

        return count;
    }
};
