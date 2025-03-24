class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int count = 0;
        int ini = 0;  // Initialize to 0
        int n = meetings.size();

        for (int i = 0; i < n; i++) {
            if ((meetings[i][0] - ini - 1) > 0) {
                count += meetings[i][0] - ini - 1;
            }
            ini = max(ini, meetings[i][1]);
        }

        // Account for remaining days
        if (days > ini) {
            count += days - ini;
        }
        
        return count;
    }
};
