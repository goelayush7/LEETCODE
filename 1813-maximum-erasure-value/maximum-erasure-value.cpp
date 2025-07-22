class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>maps;
        int i = 0;
        int cur = 0;
        int maxi = 0;
        for(int j =0;j<nums.size();j++){
            cur+=nums[j];
            maps[nums[j]]++;
            while(i<nums.size() && maps[nums[j]]>1){
                cur-=nums[i];
                maps[nums[i]]--;
                i++;
            }
            maxi = max(maxi,cur);
        }
        return maxi;
    }
};