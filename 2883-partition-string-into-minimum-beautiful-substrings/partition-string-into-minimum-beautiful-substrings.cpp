class Solution {
public:
    int helper(string s,int i,unordered_set<string>st,vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int ans = 100000;
        for(int j = i;j<s.size();j++){
            if(st.find(s.substr(i,j-i+1))!=st.end()){
                ans = min(ans,1+helper(s,j+1,st,dp));
            }
            else continue;
        }
        return dp[i] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        unordered_set<string> st{
            "11110100001001", "110000110101", "1001110001", "1111101",
            "11001",          "101",          "1"};
        vector<int>dp(s.size(),-1);

        int ans = helper(s,0,st,dp);
        if(ans==100000)return -1;
        return ans;
        
    }
};