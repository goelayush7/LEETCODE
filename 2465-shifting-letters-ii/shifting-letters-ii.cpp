class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> temp(n + 1, 0);

        // Apply the difference array technique
        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            // Update the difference array
            temp[start] += (direction == 1) ? 1 : -1;
            if (end + 1 < n) {
                temp[end + 1] += (direction == 1) ? -1 : 1;
            }
        }

        // Compute prefix sums to get cumulative shifts
        int shiftsum = 0;
        for (int i = 0; i < n; i++) {
            shiftsum = (shiftsum + temp[i]) % 26;
            if (shiftsum < 0) shiftsum += 26; // Ensure non-negative shifts
            s[i] = 'a' + (s[i] - 'a' + shiftsum) % 26; // Apply the shift
        }

        return s;
    }
};
