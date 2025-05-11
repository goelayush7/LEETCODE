class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int curcount  =0;
        for(auto it : nums){
            if(it==0){
                curcount++;
                ans+=curcount;
            }
            else curcount=0;
        }
        return ans;
    }
};