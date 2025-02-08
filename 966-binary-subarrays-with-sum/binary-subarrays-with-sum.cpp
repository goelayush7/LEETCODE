class Solution {
public:
    int helper(vector<int>&nums,int goal){
        int i = 0;
        int j = 0;
        int n = nums.size();
        int len = 0;
        int sum = 0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && sum>goal){
                sum-=nums[i];
                i++;
            }
            len+=j-i+1;
            j++;
        }
        return len;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return helper(nums,goal)-helper(nums,goal-1);
    }
};