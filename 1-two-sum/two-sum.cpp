class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        for(int i =0;i<nums.size() ; i++){
            maps[nums[i]]=i;
        }
        for(int i =0;i<nums.size();i++){
            int value = nums[i];
            int findt = target-value;
            if(maps.find(findt)!=maps.end() && maps[findt]!=i){
                return {i,maps[findt]};
            }
        }
        return {};
    }
};