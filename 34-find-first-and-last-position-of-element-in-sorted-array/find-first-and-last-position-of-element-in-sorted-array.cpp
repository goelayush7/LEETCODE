class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first =-1;
        int second = -1;
        int start = 0;
        int high = nums.size()-1;
        while(start<=high){
            int mid = (start+high)/2;
            if(nums[mid]==target){
                first=mid;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else start = mid+1;
        }
        start = 0;
        high = nums.size()-1;
        while(start<=high){
            int mid = (start+high)/2;
            if(nums[mid]==target){
                second = mid;
               start = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else start = mid+1;
        }
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(second);
        return ans;
        
    }
};