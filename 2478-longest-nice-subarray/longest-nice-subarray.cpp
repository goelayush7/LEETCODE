class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 1;
        int mask = 0;
        while(j<n){
            while((mask&nums[j])!=0){
                mask = mask^nums[i];
                i++;
            }
            mask |=nums[j];
            ans=  max(ans,j-i+1);
            j++;
        }
        return ans;
    }

};