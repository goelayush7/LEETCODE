class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp;
        for (auto s : words) {
            int it = s.size();
            // Check if the word starts and ends with a vowel
            if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
                (s[it - 1] == 'a' || s[it - 1] == 'e' || s[it - 1] == 'i' || s[it - 1] == 'o' || s[it - 1] == 'u')) {
                if (temp.size() > 0) {
                    temp.push_back(temp.back() + 1);
                } else {
                    temp.push_back(1);
                }
            } else {
                if (temp.size() > 0) {
                    temp.push_back(temp.back());
                } else {
                    temp.push_back(0);
                }
            }
        }
        
        vector<int> ans(queries.size());
        int i = 0;
        for (auto it : queries) {
            int i1 = it[0];
            int i2 = it[1];
            ans[i] = temp[i2] - (i1 == 0 ? 0 : temp[i1 - 1]);
            i++;
        }
        return ans;
    }
};
