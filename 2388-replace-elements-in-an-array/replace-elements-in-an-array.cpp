class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>maps;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            maps[nums[i]]=i;
        }
        for(auto it : operations){
            int ini = it[0];
            int newi = it[1];
            int index = maps[ini];
            nums[index] = newi;
            maps.erase(ini);
            maps[newi] = index;
        }
        return nums;
    }
};