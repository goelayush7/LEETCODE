class Solution {
public:
    bool helper(vector<int>&nums,int k,int mid){
        int i =0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                i = i+2;
                k--;
            if(k==0)return true;

            }
            else{
                i++;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(),nums.end());
        int end = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(helper(nums,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;

    }
};