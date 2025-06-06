class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        int cursum = 0;
        int j = 0;
        for(int i = 0;i<nums.size();i++){
            cursum+=nums[i];
            while(cursum>=target){
                length = min(length,i-j+1);
                cursum-=nums[j];
                j++;
            }
        }
        return length==INT_MAX?0:length;
    }
};