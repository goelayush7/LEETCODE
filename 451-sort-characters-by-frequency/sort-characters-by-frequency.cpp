class Solution {
public:
    string frequencySort(string s) {
        map<char,int>maps;
        for(int i =0;i<s.size();i++){
            maps[s[i]]++;
        }
        vector<pair<int,char>>vect;
        for(auto it : maps){
            vect.push_back({it.second,it.first});
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        string ans;
        for(auto it : vect){
           ans.append(it.first,it.second);
        }
        return ans;
    }
};