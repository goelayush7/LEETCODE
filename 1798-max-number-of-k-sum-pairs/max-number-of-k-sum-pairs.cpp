class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> maps;
        for (auto it : nums) {
            maps[it]++;
        }
        int count = 0;
        for (auto it : nums) {
            if(maps.find(it)==maps.end())continue;
            maps[it]--;
            if (maps[it] == 0)
                maps.erase(it);
            int target = k - it;
            if (maps.find(target) != maps.end()) {
                maps[target]--;

                if (maps[target] == 0)
                    maps.erase(target);
                count++;
            }
        }
        return count;
    }
};