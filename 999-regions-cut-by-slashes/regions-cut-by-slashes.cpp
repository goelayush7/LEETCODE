class Solution {
public:
    void uniqueisland(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != 0) return;
        
        matrix[i][j] = 1;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            uniqueisland(matrix, nrow, ncol);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize matrix with 0
        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0));

        // Fill matrix based on the slashes
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    uniqueisland(matrix, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
