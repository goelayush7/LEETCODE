class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        for(int i =0;i<nums.size();i++){
            if(maps.find(target-nums[i])!=maps.end()){
                int index = maps[target-nums[i]];
                return {i,index};
            }   
            else maps[nums[i]]=i;
        }
        return {};
    }
};