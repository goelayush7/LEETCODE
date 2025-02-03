class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc  = 0;
        int maxinc = 0;
        int dec = 0;
        int maxdec = 0;
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc++;
                maxinc = max(maxinc,inc);
                dec = 0;
            }
            else if(nums[i]<nums[i-1]){
                dec++;
                maxdec = max(maxdec,dec);
                inc = 0;
            }
            else{
                inc = 0;
                dec = 0;
            }
        }
        return max(maxinc,maxdec)+1;
    }
};