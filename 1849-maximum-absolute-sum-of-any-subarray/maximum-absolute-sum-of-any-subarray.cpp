class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        for(auto it : nums){
            sum+=it;
            if(sum<0)sum=0;
            ans = max(ans,sum);
        }
        sum = 0;
        for(auto it : nums){
            sum+=it;
            if(sum>0)sum=0;
            ans = max(ans,abs(sum));
        }





        return ans;
    }
};