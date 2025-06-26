class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        int j = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            maps[nums[i]]++;
            while(maps[nums[i]]>k){
                maps[nums[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};