class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // Mark guards
    for (auto &guard : guards) {
        int row = guard[0];
        int col = guard[1];
        vis[row][col] = -1;
    }

    // Mark walls
    for (auto &wall : walls) {
        int row = wall[0];
        int col = wall[1];
        vis[row][col] = -2;
    }


        for (int i = 0; i < guards.size(); i++) {
            int row = guards[i][0];
            int col = guards[i][1];

            for (int r = row - 1; r >= 0; r--) {
                if (vis[r][col] == -2 || vis[r][col] == -1)
                    break; 
                vis[r][col] = -3;
            }

            for (int r = row + 1; r < m; r++) {
                if (vis[r][col] == -2 ||vis[r][col] == -1)
                    break; 
                vis[r][col] = -3;
            }

            for (int c = col - 1; c >= 0; c--) {
                if (vis[row][c] == -2 || vis[row][c] == -1)
                    break;
                vis[row][c] = -3;
            }

            for (int c = col + 1; c < n; c++) {
                if (vis[row][c] == -2 || vis[row][c] == -1)
                    break; 
                vis[row][c] = -3;
            }
        }

        int count = 0;
   
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};