class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>maps;
        long long ans = 0;
        for(int i =0;i<nums.size();i++){
            int val = nums[i]-i;
            ans+=i-maps[val];
            maps[nums[i]-i]++;
        }
        return ans;
    }
};