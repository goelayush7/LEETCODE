class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeGaps;

        // Time before the first event
        freeGaps.push_back(startTime[0]);

        // Gaps between events
        for (int i = 1; i < n; i++) {
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        // Time after the last event
        freeGaps.push_back(eventTime - endTime[n - 1]);

        // Sliding window of size at most k+1 over freeGaps
        int maxFree = 0, currentSum = 0;
        int i = 0, j = 0, m = freeGaps.size();

        while (j < m) {
            currentSum += freeGaps[j];
            if (j - i + 1 > k + 1) {
                currentSum -= freeGaps[i];
                i++;
            }
            maxFree = max(maxFree, currentSum);
            j++;
        }

        return maxFree;
    }
};
