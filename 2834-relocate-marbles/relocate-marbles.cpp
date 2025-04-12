class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int>maps;
        for(auto it : nums){
            maps[it]++;
        }
        int n = moveFrom.size();
        for(int i=0;i<n;i++){
            if(maps.find(moveFrom[i])!=maps.end()){
                maps.erase(moveFrom[i]);
                maps[moveTo[i]]++;
            }
        }
        vector<int>ans;
        for(auto it : maps){
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};