class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countzero = 0;
        int count1 = 0;
        int ans = 0;
        int i  =0;
        int n = nums.size();
        for(int j =0;j<nums.size();j++){
            if(nums[j]==0){
                countzero++;
            }
            else count1++;
            while(countzero>1){
                if(nums[i]==0)countzero--;
                else count1--;
                i++;
            }
            ans = max(ans,count1);
        }
        if(ans==nums.size())return ans-1;
        return ans;
    }
};