class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>=nums[start]){
                ans = min(ans,nums[start]);

                start = mid+1;
            }
            else{
                end = mid-1;
                ans = min(ans,nums[mid]);
            }
        }     
            return ans;

    }
};