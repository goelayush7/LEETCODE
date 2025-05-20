class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> maps;
        for (auto it : nums) {
            maps[it]++;
        }

        vector<vector<int>> vect;

        while (!maps.empty()) {
            vector<int> temp;
            vector<int> toErase;

            for (auto& it : maps) {
                temp.push_back(it.first);
                it.second--;
                if (it.second == 0) {
                    toErase.push_back(it.first);
                }
            }

            for (int key : toErase) {
                maps.erase(key);
            }

            vect.push_back(temp);
        }

        return vect;
    }
};
