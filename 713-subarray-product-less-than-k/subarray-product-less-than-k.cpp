class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int product = 1;
        int maxi = 0;
        if(k <= 1) return 0;
        for(int right = 0;right<nums.size();right++){
            product*=nums[right];
            while(left<nums.size() && product>=k){
                product/=nums[left];
                left++;
            }
            maxi += right-left+1;
        }return maxi;
    }
};