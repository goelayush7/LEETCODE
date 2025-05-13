class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        vector<int> temp(26, 0);
        for (auto it : s) {
            temp[it - 'a']++;
        }
        while (t--) {
            vector<int> next = temp; 
            for (int i = 0; i < 26; i++) {
                if (i != 25 && temp[i] > 0) {
                    next[i + 1] = (next[i + 1] + temp[i]) % mod;
                    next[i] = (next[i] - temp[i] + mod) % mod;
                } 
                else if (i == 25 && temp[i] > 0) {
                    next[0] = (next[0] + temp[i]) % mod;
                    next[1] = (next[1] + temp[i]) % mod;
                    next[25] = (next[25] - temp[i] + mod) % mod;
                }
            }
            temp = next;
        }
        int ans = 0;
        for (auto it : temp) {
            ans = (ans + it) % mod;
        }
        return ans;
    }
};
