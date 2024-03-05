class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            //check for sorted part 
            if(nums[start]<=nums[mid]){                       //left part is sorted
                if(nums[start]<=target && nums[mid]>target){
                    end = mid-1;
                }
                else start = mid+1;
            }
            //right part is sorted
           else{
                if(nums[mid]<target && nums[end]>=target){
                    start = mid+1;
                }
                else end = mid-1;
           }
        }
        return -1;
    }
};