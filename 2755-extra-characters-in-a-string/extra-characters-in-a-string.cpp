class Solution {
public:
    int func(int i , int j , string s  , unordered_map<string,int> &mpp , vector<vector<int>> &dp){
        int n = s.length();
        if(j == n) return n-i;
        if(dp[i][j] != -1) return dp[i][j];


        int take = func(i , j+1 , s , mpp , dp);
        int not_take;
        if(mpp.find(s.substr(i , j-i+1)) != mpp.end()){
            not_take = func(j+1 , j+1 , s , mpp , dp);
        }
        else{
            not_take = (j-i+1) + func(j+1 , j+1 , s , mpp ,dp);
        }

        return dp[i][j] = min(take , not_take);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string , int> mpp;
        for(auto it : dictionary){
            mpp[it]++;
        }
        int n = s.length();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
        return func(0 , 0 , s , mpp , dp);
    }
};