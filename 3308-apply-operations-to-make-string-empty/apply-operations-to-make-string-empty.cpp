class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int>maps;
        for(auto it : s){
            maps[it]++;
        }
        unordered_map<char,int>maps1;
        int maxi = 0;
        for(auto it : maps){
            maxi = max(it.second,maxi);
        }
        for(auto it : maps){
            if(it.second==maxi){
                maps1[it.first]++;
            }
        }
        string ans ;
        for(int i = s.size()-1;i>=0;i--){
            if(maps1.find(s[i])!=maps.end()){
                if(maps[s[i]]==maxi){
                    ans.push_back(s[i]);
                    maps[s[i]]--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};