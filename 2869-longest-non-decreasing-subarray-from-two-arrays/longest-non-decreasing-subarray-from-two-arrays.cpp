typedef vector<vector<int>> vvi;
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans =1;
        int n = nums1.size();
        vvi dp(n,vector<int>(2,1));
        for(int i =0;i<n;i++){
            if(i==0){
                dp[i][0] = dp[i][1]=1;
            }
            else{
                if(nums1[i]>=nums1[i-1]){
                    dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
                }
                if(nums1[i]>=nums2[i-1]){
                    dp[i][0] = max(dp[i][0],dp[i-1][1]+1);
                }
                 if(nums2[i]>=nums1[i-1]){
                    dp[i][1] = max(dp[i][1],dp[i-1][0]+1);
                }
                if(nums2[i] >= nums2[i-1]){
                    dp[i][1] = max(dp[i][1] , dp[i-1][1]+1);
                }
                ans = max(ans,dp[i][0]);
                ans = max(ans,dp[i][1]);
            }
        }
        return ans;
    }
};