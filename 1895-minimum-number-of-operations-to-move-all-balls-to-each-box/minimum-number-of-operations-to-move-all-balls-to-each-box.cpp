class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        // First pass (left-to-right)
        int count1 = 0; // Number of balls seen so far
        int sum = 0;    // Sum of operations for the current index
        for (int i = 0; i < n; i++) {
            ans[i] = sum;
            if (boxes[i] == '1') {
                count1++;
            }
            sum += count1;
        }

        // Second pass (right-to-left)
        count1 = 0;
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += sum;
            if (boxes[i] == '1') {
                count1++;
            }
            sum += count1;
        }

        return ans;
    }
};
