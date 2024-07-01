class Solution {
public:
    void dfs(vector<vector<int>> & vis, vector<vector<int>>& grid, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1) {
                    vis[nrow][ncol]=1;
                    dfs(vis,grid,nrow,ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n - 1 || i == 0 || j == m - 1 || j == 0) {
                    if (grid[i][j] == 1) {
                        vis[i][j] = 1;
                        dfs(vis, grid, i, j);
                    }
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    count++;
                }
            }
        }
        return count;
    }
};