class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>maps;
        for(auto it : nums){
            maps[it]++;
        }
        for(auto it : maps){
            if(it.second%2!=0)return false;
        }
        return true;
    }
};