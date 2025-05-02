class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> suffix(n + 1, 0); // Y after closing
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                sum++;
            }
            suffix[i] = sum;
        }

        vector<int> prefix(n + 1, 0); // N before closing
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N') {
                sum++;
            }
            prefix[i + 1] = sum;  // fix: store at i+1 to match suffix index
        }

        int mini = INT_MAX;
        int index = -1;
        for (int i = 0; i <= n; i++) {
            int penalty = prefix[i] + suffix[i];
            if (penalty < mini) {
                mini = penalty;
                index = i;
            }
        }

        return index;
    }
};
