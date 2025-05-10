class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<tuple<int, string>, set<string>> maps;
        unordered_map<string, int> maps2;

        // Step 1: Build substrings and frequency map
        for (int k = 0; k < arr.size(); ++k) {
            string word = arr[k];
            int n = word.size();
            for (int i = 0; i < n; ++i) {
                string sub = "";
                for (int j = i; j < n; ++j) {
                    sub += word[j];
                    auto key = make_tuple(k, word);
                    if (maps[key].find(sub) == maps[key].end()) {
                        maps[key].insert(sub);
                        maps2[sub]++;
                    }
                }
            }
        }

        // Step 2: Find shortest unique substring for each word
        vector<string> ans;
        for (int k = 0; k < arr.size(); ++k) {
            string word = arr[k];
            string shortest = "";
            auto key = make_tuple(k, word);
            for (const string& s : maps[key]) {
                if (maps2[s] == 1) {
                    if (shortest.empty() ||
                        s.length() < shortest.length() ||
                        (s.length() == shortest.length() && s < shortest)) {
                        shortest = s;
                    }
                }
            }
            ans.push_back(shortest);
        }

        return ans;
    }
};
