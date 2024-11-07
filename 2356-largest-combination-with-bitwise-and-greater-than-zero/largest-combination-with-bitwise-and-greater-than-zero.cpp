class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int,int>maps;
        for(int i =0;i<candidates.size();i++){
            int num = candidates[i];
            for(int j=0;j<24;j++){
                if(num & (1<<j)){
                    maps[j]++;
                }
            }
        }
        int ans =0;
        for(auto it : maps){
            ans = max(ans,it.second);
        }
        return ans;
    }
};