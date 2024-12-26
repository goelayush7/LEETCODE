class Solution {
public:
    void countans(vector<int>&nums,int target,int i,int n,int& count){
        if(i==n){
            if(target==0)count++;
            return;
        }
        //take as it is
        countans(nums,target-nums[i],i+1,n,count);
        //take negative
        countans(nums,target+nums[i],i+1,n,count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count =0;
        int n = nums.size();
        countans(nums,target,0,n,count);
        return count;
    }
};