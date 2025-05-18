class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans =0;
        int maxians = 0;
        for(auto it : nums){
            if(it==maxi){
                ans++;
                maxians = max(maxians,ans);
            }
            else ans = 0;
        }
        return maxians;
    }
};