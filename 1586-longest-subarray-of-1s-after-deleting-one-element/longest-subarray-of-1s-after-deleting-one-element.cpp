class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0);
        int count =0;
        for(int i = 0;i<nums.size();i++){
            left[i] = count;
            if(nums[i]==0)count=0;
            else count++;
            
        }
        vector<int>right(n,0);
        count  = 0;
        for(int i = n-1;i>=0;i--){
            right[i] = count;
            if(nums[i]==0)count=0;
            else count++;
            
        }
        int ans =0;
        bool findzero = false;
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                findzero = true;
                ans = max(ans,left[i]+right[i]);
            }
        }
        if(!findzero)return n-1;
        return ans;

    }
};