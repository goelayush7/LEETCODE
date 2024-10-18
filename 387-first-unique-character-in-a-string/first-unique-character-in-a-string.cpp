class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>maps;
        for(auto it : s){
            maps[it]++;
        }
        int ans = -1;
        for(int i =0;i<s.size();i++){
            if(maps[s[i]]==1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};