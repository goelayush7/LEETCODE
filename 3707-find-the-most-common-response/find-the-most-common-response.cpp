class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        unordered_map<string,int>maps;
        for(int i = 0;i<n;i++){
            vector<string>temp = responses[i];
            set<string>set(temp.begin(),temp.end());
            for(auto it : set){
                maps[it]++;
            }
        }
        int maxi = 0;
        string ans = "";
        for(auto it : maps){
            if(it.second>maxi){
                maxi = it.second;
                ans = it.first;
            }
            if(it.second==maxi){
                ans = min(ans,it.first);
            }
        }
        return ans;
    }
};