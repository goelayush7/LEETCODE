

class Solution {
public:
    bool helper(vector<int>& position, int m, int mid) {
        int lastpos = position[0];
        int ballsplaced = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastpos >= mid) {
                ballsplaced++;
                lastpos = position[i];
                if (ballsplaced == m) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1; // The minimum possible distance
        int end = position.back() - position.front(); // The maximum possible distance
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (helper(position, m, mid)) {
                ans = mid; // Update the answer with the current mid if valid
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
