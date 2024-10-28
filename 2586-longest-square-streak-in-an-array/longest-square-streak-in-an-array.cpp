#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> st(nums.begin(), nums.end()); // Initialize set with nums
        int maxcount = 1;

        for (auto x : st) {
            // Check if x is the beginning of a potential square streak
            if (st.find((long long)sqrt(x)) == st.end() || sqrt(x) * sqrt(x) != x) {
                int count = 1;
                long long it = x;
                
                // Continue the streak by squaring `it` and checking if it's in the set
                while (st.find(it * it) != st.end()) {
                    count++;
                    it = it * it;
                }

                maxcount = max(maxcount, count);
            }
        }

        return maxcount == 1 ? -1 : maxcount;
    }
};
