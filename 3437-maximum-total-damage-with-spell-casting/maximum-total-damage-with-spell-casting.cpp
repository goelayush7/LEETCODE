#define ll long long

class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        map<ll, ll> freq;
        for (auto p : power) {
            freq[p]++;
        }

        unordered_map<ll, ll> dp;
        ll ans = 0, backele = 0, prevele = 0;
        map<ll, ll>::iterator backitr;
        
        for (auto [ele, fr] : freq) {
            backitr = freq.lower_bound(ele - 2);
            if (backitr != freq.begin()) backele = (*(--backitr)).first;
            else backele = 0;
            
            dp[ele] = max(dp[prevele], ele * fr + dp[backele]);
            ans = max(ans, dp[ele]);
            prevele = ele;
        }
        
        return ans;
    }
};
