class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin(),nums.end());
        int n =nums.size();
        int i = 0;
        int count =0;
        long long ans = 0;
        for(int j = 0;j<n;j++){
            if(nums[j]==maxi)count++;
            while(count>=k){
                if(nums[i]==maxi)count--;
                i++;
                ans+=n-j;
            }
        }
        return ans;
    }
};