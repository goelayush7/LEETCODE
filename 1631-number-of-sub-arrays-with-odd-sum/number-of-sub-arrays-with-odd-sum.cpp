class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<long long> temp(2, 0); // 0 for even, 1 for odd
        long long prefix = 0;
        long long ans = 0;
        const int MOD = 1e9 + 7; // To prevent overflow

        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            if (prefix % 2 != 0) ans++;
            
            if (prefix % 2 == 0) {
                if (temp[1] > 0) ans += temp[1];
                temp[0]++;
            } else {
                if (temp[0] > 0) ans += temp[0];
                temp[1]++;
            }

            ans %= MOD; // Apply modulo to prevent overflow
        }
        
        return ans;
    }
};
