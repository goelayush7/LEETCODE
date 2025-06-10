class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>maps;
        for(auto it : s){
            maps[it]++;
        }
        int odd = 0;
        int even = INT_MAX;
        for(auto it : maps){
            if(it.second%2==0){
                even = min(even,it.second);
            }
            else odd = max(odd,it.second);
        }
        if(even==INT_MAX)even = 0;
        return odd-even;
    }
};