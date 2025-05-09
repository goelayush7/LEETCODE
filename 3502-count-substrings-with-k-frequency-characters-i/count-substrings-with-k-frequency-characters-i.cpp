class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int j = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<int,int>maps;
        for(int i = 0;i<n;i++){
            maps[s[i]]++;
            while(maps[s[i]]>=k){
                ans+=n-i;
                maps[s[j]]--;
                j++;
            }
        }   
        return ans;
    }
};