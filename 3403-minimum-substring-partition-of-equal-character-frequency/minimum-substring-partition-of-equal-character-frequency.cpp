#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits> // for INT_MAX
#include <cstring> // for memset
using namespace std;

class Solution {
public:
    bool chk(map<int,int> &mp){
        if(mp.size() == 0) return true;
        
        auto firstElement = mp.begin();
        int freq = firstElement->second;
        
        for(auto &[ele, f]: mp){
            if(f != freq) return false;
        }
        return true;
    }
    
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        int dp[n + 1]; // dp array to store the minimum number of partitions needed for each prefix
        memset(dp, -1, sizeof(dp));
        dp[n] = 0; // Base case: if i is equal to s.size(), set dp[i] to 0
        
        for (int i = n - 1; i >= 0; i--) {
            int ans = n;
            map<int, int> mp;
            
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                
                if (chk(mp)) {
                    ans = min(ans, 1 + dp[j + 1]);
                }
            }
            
            dp[i] = ans;
        }
        
        return dp[0];
    }
};
