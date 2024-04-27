class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();  

        vector<int> rowmap(n, 0);  
        vector<int> colmap(m, 0);  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowmap[i]++;
                    colmap[j]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int rowcount = rowmap[i] - 1;  
                    int colcount = colmap[j] - 1;  
                    if (rowcount > 0 && colcount > 0) {
                        ans += rowcount * colcount;
                    }
                }
            }
        }

        return ans;
        
    }
};