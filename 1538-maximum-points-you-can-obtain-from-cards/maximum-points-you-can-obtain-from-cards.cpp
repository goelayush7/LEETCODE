class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int len = n-k;
        int i =0;
        int j = 0;
        int sum = 0;
        int totalsum = 0;
        for(auto it : cardPoints){
            totalsum+=it;
        }
        while(j<len){
            sum+=cardPoints[j];
            j++;
        }
        int ans = 0;
        ans = max(ans,totalsum-sum);
        while(j<n){
            sum+=cardPoints[j];
            sum-=cardPoints[i];
            i++;
            j++;
            ans = max(ans,totalsum-sum);
        }
        return ans;
    }
};