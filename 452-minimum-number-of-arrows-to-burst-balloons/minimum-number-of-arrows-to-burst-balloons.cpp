#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int count = 0;
        int i = 0;
        while (i < n) {
            int end = points[i][1];
            count++;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] <= end) {
                    // Update end to the minimum of the current end and the end of the overlapping interval
                    end = min(end, points[j][1]);
                    i++;
                } else {
                    break; // No more overlapping intervals
                }
            }
            i++;
        }
        return count;
    }
};
