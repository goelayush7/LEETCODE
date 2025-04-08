class Solution {
public:
    int helper(string word1,string word2,int index1,int index2,vector<vector<int>>&dp){
        if(index1>=word1.size() || index2>=word2.size()){
            return 0;
        }
        if(index1==word1.size()-1 && index2==word2.size()-1){
            return word1[index1]==word2[index2];
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }

        int equal = 0;
        if(word1[index1]==word2[index2]){
            equal = 1 + helper(word1,word2,index1+1,index2+1,dp);
        }
        int notequal = max(helper(word1,word2,index1+1,index2,dp),helper(word1,word2,index1,index2+1,dp));
        return dp[index1][index2] = max(equal,notequal);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int lcs = helper(word1,word2,0,0,dp);
        return (word1.size()-lcs) + (word2.size()-lcs);
    }
};