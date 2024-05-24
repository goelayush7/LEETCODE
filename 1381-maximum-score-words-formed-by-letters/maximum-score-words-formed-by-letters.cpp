#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int helper(vector<string>& words, vector<int>& letterScores, int i, vector<int>& remainingLetters) {
        if (i == words.size())
            return 0;

        // Calculate the score if we don't pick the current word
        int nonPick = helper(words, letterScores, i + 1, remainingLetters);

        // Try to pick the current word
        int pick = 0;
        bool canPick = true;
        vector<int> temp = remainingLetters;
        for (char c : words[i]) {
            if (--temp[c - 'a'] < 0) {
                canPick = false;
            }
            pick += letterScores[c - 'a'];
        }

        int result = 0;
        if (canPick) {
            pick += helper(words, letterScores, i + 1, temp);
            result = max(pick, nonPick);
        } else {
            result = nonPick;
        }

        return result;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& letterScores) {
        vector<int> remainingLetters(26, 0);
        for (char c : letters) {
            remainingLetters[c - 'a']++;
        }
        return helper(words, letterScores, 0, remainingLetters);
    }
};
