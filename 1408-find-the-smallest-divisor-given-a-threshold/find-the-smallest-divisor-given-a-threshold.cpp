class Solution {
public:
    bool func(vector<int>&nums,int threshold,int mid){
        int value =0;
        for(auto it:nums){
            value+=(it+mid-1)/mid;
        }
        return value<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans =0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(func(nums,threshold,mid)){
                ans=mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};