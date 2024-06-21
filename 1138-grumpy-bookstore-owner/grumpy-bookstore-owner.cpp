class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = grumpy.size();
        int wpo = 0; // Initialize window satisfied customers

        // Pre-calculate satisfied customers when not grumpy
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                wpo += customers[i];
            }
        }

        int i = 0, j = 0;
        int maxi = 0; // Maximum satisfied customers in a window

        // Slide the window and update wpo
        while (j < k) {
            wpo += grumpy[j] * customers[j]; // Add customers only if grumpy in window
            j++;
            maxi = max(maxi, wpo);
        }

        while (i < n && j < n) {
            wpo -= grumpy[i] * customers[i]; // Remove customers if grumpy leaving window
            i++;
            wpo += grumpy[j] * customers[j]; // Add customers if grumpy entering window
            maxi = max(maxi, wpo);
            j++;
        }

        return maxi;
    }
};
