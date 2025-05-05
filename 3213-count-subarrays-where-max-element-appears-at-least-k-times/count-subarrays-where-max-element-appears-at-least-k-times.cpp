class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int ele = *max_element(nums.begin(),nums.end());
        int count  =0;
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==ele){
                count++;
            }
            while(count==k){
                ans+=n-j;
                if(nums[i]==ele){
                    count--;
                }
                i++;
            }
        }
        return ans;
    }
};