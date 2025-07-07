class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& vis) {
                int n = grid.size();
                int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;

            for (int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==-1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == -1) {
                    count++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return count;
    }
};