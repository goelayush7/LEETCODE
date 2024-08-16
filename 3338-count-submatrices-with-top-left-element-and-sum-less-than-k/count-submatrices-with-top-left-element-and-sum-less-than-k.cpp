class Solution {
public:
    vector<vector<int>> countval(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> val(rows, vector<int>(cols, 0));  // Initialize correctly

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                val[row][col] = grid[row][col];
                if (row > 0) val[row][col] += val[row - 1][col];
                if (col > 0) val[row][col] += val[row][col - 1];
                if (row > 0 && col > 0) val[row][col] -= val[row - 1][col - 1];
            }
        }
        return val;
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>val = countval(grid);
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(val[i][j]<=k)ans++;
            }
        }
        return ans;
        
    }
};