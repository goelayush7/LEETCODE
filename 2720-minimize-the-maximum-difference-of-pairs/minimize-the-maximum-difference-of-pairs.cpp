class Solution {
public:
    bool helper(int mid,vector<int>&nums,int p){
        int pair = 0;
        int i = 0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=mid){
                pair++;
                i+=2;
            }
            else i = i+1;
        }
        if(pair>=p)return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int start  = 0;
        int end = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(helper(mid,nums,p)==true){
                end = mid-1;
                ans = min(ans,mid);
            }
            else start = mid+1;
        }
        return ans;
    }
};