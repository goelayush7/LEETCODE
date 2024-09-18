class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // We create a vector to store the farthest point each index can cover
        vector<int> maxRange(n + 1, 0);
        
        // Populate the `maxRange` based on the ranges given
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);  // Leftmost point this tap can cover
            int right = min(n, i + ranges[i]); // Rightmost point this tap can cover
            maxRange[left] = max(maxRange[left], right); // Store the max coverage for the left point
        }

        int taps = 0, curEnd = 0, maxEnd = 0;

        for (int i = 0; i <= n; i++) {
            if (i > maxEnd) return -1; // If we can't reach this point, return -1
            
            if (i > curEnd) {
                // When we exceed the current range, we need to open a new tap
                taps++;
                curEnd = maxEnd; // Update the current range to the maximum reachable so far
            }

            // Update the maximum reach
            maxEnd = max(maxEnd, maxRange[i]);
        }

        return taps;
    }
};
