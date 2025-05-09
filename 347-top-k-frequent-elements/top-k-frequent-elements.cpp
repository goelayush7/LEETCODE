class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        for(auto it : nums){
            maps[it]++;
        }
        vector<pair<int,int>>vect;
        for(auto it : maps){
            vect.push_back({it.second,it.first});
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        vector<int>ans;
        int i = 0;
        while(k-- && i<vect.size()){
            ans.push_back(vect[i].second);
            i++;
        }
        return ans;
    }
};