class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j =0;
        int n = s.size();
        unordered_map<int,int>maps;
        int maxi = 0;
        while(j<n){
            maps[s[j]]++;
            while(maps[s[j]]>1){
                maps[s[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};