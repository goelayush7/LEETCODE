class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= right; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= right; i += p)
                    prime[i] = false;
            }
        }
        int dis = INT_MAX;
        int ini = -1;
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (!prime[i])
                continue;
            else if (ini == -1 && prime[i]) {
                ini = i;
            } else {
                if (dis > i - ini) {
                    dis = i-ini;
                    ans = {ini, i};
                }
                    ini = i;

            }
        }
        if(dis==INT_MAX)return {-1,-1};
        return ans;
    }
};