class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>maps;
        for(auto it : nums1){
            maps[it]++;
        }
        unordered_set<int>set;
        for(auto it : nums2){
            if(maps.find(it)!=maps.end()){
                set.insert(it);
            }
        }
        vector<int>ans;
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;
    }
};