class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int drow[] = {-1, 0, 1, 0};  // Direction vectors for row (up, right, down, left)
        int dcol[] = {0, 1, 0, -1};  // Direction vectors for column (up, right, down, left)
        q.push({row, col});
        vis[row][col] = 1;  // Mark starting cell as visited
        int count = 0;

        // Perform BFS
        while (!q.empty()) {
            count++;  // Count each cell in the island
            auto front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check bounds, if it's land ('1'), and if it hasn't been visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;  // Mark as visited when pushing into the queue
                }
            }
        }
        return count;  // Return the area of the island
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited grid

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int val = bfs(grid, vis, i, j);
                    maxi = max(maxi, val); 
                }
            }
        }
        return maxi;  
}
};
