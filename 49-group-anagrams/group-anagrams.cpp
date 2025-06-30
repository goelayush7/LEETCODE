class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>maps;
        for(auto it : strs){
            string cpy = it;
            sort(it.begin(),it.end());
            if(maps.find(it)!=maps.end()){
                maps[it].push_back(cpy);
            }
            else maps[it].push_back(cpy);
        }
        vector<vector<string>>ans;
        for(auto it : maps){
            vector<string>vect;
            for(auto it1 : maps[it.first]){
                vect.push_back(it1);
            }
            ans.push_back(vect);
        }
        return ans;
    }
};