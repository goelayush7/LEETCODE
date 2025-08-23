class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // frequency map for first word
        map<char, int> maps;
        for (auto ch : words[0]) {
            maps[ch]++;
        }

        // intersect frequencies with all other words
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> temp;
            for (auto ch : words[i]) {
                temp[ch]++;
            }
            for (auto &kv : maps) {
                char c = kv.first;
                maps[c] = min(maps[c], temp[c]);
            }
        }

        // build result
        vector<string> vect;
        for (auto it : maps) {
            char c = it.first;
            int count = it.second;

            for (int i = 0; i < count; i++) {
                string ans(1, c);   // convert char -> string
                vect.push_back(ans);
            }
        }
        return vect;
    }
};
