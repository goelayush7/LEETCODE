class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        int n = nums.size();
        for(int i =0;i<n ; i++){
            maps[nums[i]]=i;
        }
        vector<int>ans;
        for(int i =0 ;i< n; i++){
            int t = target-nums[i];
            if(maps.find(t)!=maps.end() && maps[t]!=i){
                return {i,maps[t]};
            }
        }
        return {};
        
    }
};