class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return nums[mid];
    }
};