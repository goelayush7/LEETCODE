class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long long ans = 0;
        int minusvalue = 0;
        int i = 0;
        while(k--){
            int value = happiness[i]-minusvalue;
            if(value>0)ans+=happiness[i]-minusvalue;
            minusvalue++;
            i++;
        }
        return ans;
    }
};