class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int cur = 0;
        for(auto it : nums){
            cur+=it;
            maxi = max(maxi,cur);
            if(cur<0)cur=0;
        }
        return maxi;
    }
};