class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> maps;
        for (auto& word : words) {
            maps[word]++;
        }

        int count = 0;
        bool hasMiddle = false;

        for (auto& [word, freq] : maps) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (rev == word) {
                count += (freq / 2) * 4;
                if (freq % 2 == 1) hasMiddle = true;
            } else if (maps.find(rev) != maps.end()) {
                int pairs = min(freq, maps[rev]);
                count += pairs * 4;
                maps[rev] = 0; 
                maps[word] = 0;
            }
        }

        if (hasMiddle) count += 2;

        return count;
    }
};
