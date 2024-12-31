class Solution {
public:
    // Helper function with memoization
    int check(vector<int>& days, vector<int>& costs, int i, vector<int>& memo) {
        // Base case: if all days are processed
        if (i >= days.size()) return 0;

        // If the result is already computed, return it
        if (memo[i] != -1) return memo[i];

        // Calculate the minimum cost
        int option1 = costs[0] + check(days, costs, i + 1, memo); // 1-day pass

        // Find the next index for a 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int option2 = costs[1] + check(days, costs, j, memo); // 7-day pass

        // Find the next index for a 30-day pass
        int k = i;
        while (k < days.size() && days[k] < days[i] + 30) k++;
        int option3 = costs[2] + check(days, costs, k, memo); // 30-day pass

        // Store the result in memo
        memo[i] = min({option1, option2, option3});
        return memo[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1); // Initialize memoization table
        return check(days, costs, 0, memo);
    }
};
