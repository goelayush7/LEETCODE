class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>maps;
        int i = 0;
        int j = 9;
        while(j<s.size()){
            string temp = s.substr(i,j-i+1);
            maps[temp]++;
            j++;
            i++;
        }
        vector<string>ans;
        for(auto it : maps){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};