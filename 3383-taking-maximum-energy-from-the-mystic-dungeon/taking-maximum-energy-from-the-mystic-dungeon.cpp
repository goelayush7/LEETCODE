class Solution {
public:
    
    int solve(vector<int>& energy, int idx, int k, vector<int> &memo){
        int n = energy.size();
        
        if(idx >= n) return 0;
        
        if(memo[idx] != INT_MIN) return memo[idx];
        
        int ans = energy[idx] + solve(energy, idx + k, k, memo);
        
        return memo[idx] = ans;
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        
        vector<int> memo(n, INT_MIN);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, solve(energy, i, k, memo));
        }
        
        return ans;
    }
};