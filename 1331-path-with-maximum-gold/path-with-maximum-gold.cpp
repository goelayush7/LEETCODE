class Solution {
public:
    int maxgold = 0;
    int func(vector<vector<int>>&grid,int i ,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0){
            return 0;
        }
        int val = grid[i][j];
        grid[i][j] = 0; // Mark as visited
        int down = val + func(grid, i, j + 1);
        int up = val + func(grid, i, j - 1);
        int right = val + func(grid, i + 1, j);
        int left = val + func(grid, i - 1, j);
        grid[i][j] = val; // Reset to original value
        return max(down, max(up, max(left, right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int gold = 0; // Initialize gold
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxgold = max(maxgold, func(grid, i, j));
            }
        }
        return maxgold;
    }
};
