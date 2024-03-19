class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        int end = n-1;
        long long sum = 0;
        int minusterm = 1;
        sort(happiness.begin(),happiness.end());
        while(k!=0){
            if(happiness[end]>0){
                sum+=happiness[end];
            }
            end--;
            if(end<0)break;
            happiness[end]-=minusterm;
            minusterm++;
            k--;
        }
        return sum;
    }
};