class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> ltr(n, 0), rtl(n, 0);
        unordered_map<char, int> leftMap, rightMap;

        for (int i = 0; i < n; ++i) {
            leftMap[s[i]]++;
            ltr[i] = leftMap.size();
        }

        for (int i = n - 1; i >= 0; --i) {
            rightMap[s[i]]++;
            rtl[i] = rightMap.size();
        }

        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (ltr[i] == rtl[i + 1]) count++;
        }

        return count;
    }
};
