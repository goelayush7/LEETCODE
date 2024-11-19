class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i  =0;
        int j  =0;
        int n = nums.size();
        unordered_map<long long,long long>maps;
        long long sum = 0;
        long long maxi = 0;
        while(j<k){
            maps[nums[j]]++;
            sum+=nums[j];
            j++;
        }
        if(maps.size()==k)maxi = max(maxi,sum);

        while(j<n){
            sum-=nums[i];
            maps[nums[i]]--;
            if(maps[nums[i]]==0)maps.erase(nums[i]);
            i++;
            maps[nums[j]]++;
            sum+=nums[j];
            if(maps.size()==k)maxi=max(maxi,sum);
            j++;
        }
        return maxi;

    }
};