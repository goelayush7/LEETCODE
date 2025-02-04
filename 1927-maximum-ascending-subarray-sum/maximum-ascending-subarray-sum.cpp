class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans= nums[0] ;
        int maxi = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans+=nums[i];
                maxi = max(ans,maxi);
            }
            else ans = nums[i];
        }
        return maxi;
    }
};