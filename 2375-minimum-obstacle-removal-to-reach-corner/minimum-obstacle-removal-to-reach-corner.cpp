#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> mindis(m, vector<int>(n, INT_MAX));
        mindis[0][0] = grid[0][0];
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({mindis[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto current = pq.top(); 
            pq.pop();
            
            int obstacles = current[0];
            int row = current[1];
            int col = current[2];
            
            if (row == m - 1 && col == n - 1) {
                return obstacles;
            }
            
            for (auto dir : directions) {
                int newrow = row + dir[0];
                int newcol = col + dir[1];
                
                if (isValid(grid, newrow, newcol)) {
                    int newobs = obstacles + grid[newrow][newcol];
                    
                    if (newobs < mindis[newrow][newcol]) {
                        mindis[newrow][newcol] = newobs;
                        pq.push({newobs, newrow, newcol});
                    }
                }
            }
        }
        
        return mindis[m - 1][n - 1];
    }
};
