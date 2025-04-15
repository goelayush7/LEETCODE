class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int count = 0;
        int n = s.size();
        unordered_map<char, int> maps;

        while (j < s.size()) {
            maps[s[j]]++; 
            while (maps.size() == 3) {
                count += n - j;  
                maps[s[i]]--;  
                if (maps[s[i]] == 0) {
                    maps.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};
