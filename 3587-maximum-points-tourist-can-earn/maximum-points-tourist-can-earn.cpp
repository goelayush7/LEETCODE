class Solution {
public:
    int helper(vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,int cur,int day,int k,int n,vector<vector<int>>&dp){
        if(day==k)return 0;
        if(dp[cur][day]!=-1)return dp[cur][day];
        int stay = stayScore[day][cur]+helper(stayScore,travelScore,cur,day+1,k,n,dp);
        int travel=INT_MIN;
        for(int des=0;des<n;des++){
            if(des!=cur){
                travel = max(travel,travelScore[cur][des]+helper(stayScore,travelScore,des,day+1,k,n,dp));
            }
        }
        return dp[cur][day]= max(travel,stay);
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
            vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
            int ans =0;
            for(int i =0;i<n;i++){
                ans = max(ans,helper(stayScore,travelScore,i,0,k,n,dp));
            }
            return ans;

    }
};