class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int curcount = 0;
                int sum = 0;
                for (int index = i + 1; index < n + index; index++) {
                    if (curcount == k) {
                        ans[i] = sum;
                        break;
                    }
                    curcount++;
                    sum += code[index % n];
                }
            }
        } else if (k < 0) {
            k = -k; // Convert k to positive for convenience
            for (int i = n - 1; i >= 0; i--) {
                int curcount = 0;
                int sum = 0;
                // Sum the previous k elements in a circular manner
                for (int index = i - 1; curcount < k; index--) {
                    sum += code[(index + n) % n]; // Wrap around using modulo
                    curcount++;
                }
                ans[i] = sum;
            }
        }

        return ans;
    }
};