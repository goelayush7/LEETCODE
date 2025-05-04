class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chains;

        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int ans = 0;
        for (const string& word : words) {
            chains[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (chains.find(pred) != chains.end()) {
                    chains[word] = max(chains[word], chains[pred] + 1);
                }
            }
            ans = max(ans, chains[word]);
        }

        return ans;
    }
};
