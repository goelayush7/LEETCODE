class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans =0;
        for(int i =0;i<n;i++){
            map<char,int>maps;
            for(int j=i;j<n;j++){
                maps[s[j]]++;
                int mincount = INT_MAX;
                int maxcount = INT_MIN;
                for(auto it : maps){
                    mincount = min(mincount,it.second);
                    maxcount = max(maxcount,it.second);
                }
                ans += maxcount-mincount;
            }
        }
        return ans;
    }
};