class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int i = 0, j = 0; // Two pointers for sliding window
        int count = 0;    // To count the valid substrings
        int n = s.size(); // Size of the string
        unordered_map<char, int> maps; // Map to store frequency of characters

        while (i < n) {
            // Increment the frequency of the character at position i
            maps[s[i]]++;

            // If the frequency of the current character is greater than or equal to k
            while (maps[s[i]] >= k) {
                // Every substring starting from `i` to the end is valid
                count += n - i;

                // Now try to shrink the window from the left (increment `j`)
                maps[s[j]]--;
                j++; // Move `j` to shrink the window
            }

            i++;
        }

        return count;
    }
};
