
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int row = 0;
        int col = 0;
        int n = grid.size();
        while (row < n - 2) { // Adjusted loop condition to avoid out-of-bound access
            col = 0; // Reset col for each row iteration
            vector<int> out;
            while (col < n - 2) { // Adjusted loop condition to avoid out-of-bound access
                int maxnum = INT_MIN;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        maxnum = max(maxnum, grid[i][j]);
                    }
                }
                out.push_back(maxnum);
                col++; // Increment col to slide the window
            }
            ans.push_back(out);
            row++; // Increment row to slide the window
        }
        return ans;
    }
};
