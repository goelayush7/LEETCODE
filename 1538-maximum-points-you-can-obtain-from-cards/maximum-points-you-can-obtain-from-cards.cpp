class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =  accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int n = cardPoints.size();
        int windowsize = n-k;
        int i = 0;
        int j = 0;
        int cursum = 0;
        int outsum =0;
        int maxsum = 0;
        while(j<windowsize){
            cursum+=cardPoints[j];
            j++;
        }
        outsum = sum-cursum;
        maxsum = max(maxsum,outsum);
        while(j<n){
            cursum-=cardPoints[i];
            i++;
            cursum+=cardPoints[j];
            j++;
            outsum = sum-cursum;
            maxsum = max(maxsum,outsum);
        }
        return maxsum;
    }
};