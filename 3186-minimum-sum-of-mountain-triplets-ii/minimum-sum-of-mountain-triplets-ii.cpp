class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftmin(n,0);
        vector<int>rightmin(n,0);
        leftmin[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            leftmin[i] = min(leftmin[i-1],nums[i]);
        }
        rightmin[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            rightmin[i] = min(rightmin[i+1],nums[i]);
        }
        int ans = INT_MAX;
        for(int i =0;i<n;i++){
            if(leftmin[i]<nums[i] && rightmin[i]<nums[i]){
                int val = nums[i]+leftmin[i]+rightmin[i];
                ans = min(ans,val);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};