#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        distance[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            for (auto& d : directions) {
                int nextRow = row + d[0], nextCol = col + d[1];
                
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                    int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                    
                    if (nextTime < distance[nextRow][nextCol]) {
                        distance[nextRow][nextCol] = nextTime;
                        pq.push({nextTime, nextRow, nextCol});
                    }
                }
            }
        }
        return -1;
    }
};
