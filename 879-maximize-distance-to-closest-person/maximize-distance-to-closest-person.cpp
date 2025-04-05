class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> left(seats.size(), INT_MAX);
        int start = 1000000;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                left[i] = 1e9;
                start = 0;
            } else {
                start++;
                left[i] = start;
            }
        }
        vector<int> right(seats.size(), INT_MAX);
        start = 1000000;
        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                right[i] = 1e9;
                start = 0;
            } else {
                start++;
                right[i] = start;
            }
        }
        int finalans;
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] != 1) {
                finalans = min(left[i], right[i]);
                ans = max(ans, finalans);
            }
        }
        return ans;
    }
};