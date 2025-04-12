class Solution {
public:
    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& st, int row,
             int col) {
        int m = heights.size();
        int n = heights[0].size();
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        st.insert({row, col});
        int num = heights[row][col];
        for (int i = 0; i < 4; i++) {
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                st.find({nrow, ncol}) == st.end() &&
                heights[nrow][ncol] >= num) {
                dfs(heights, st, nrow, ncol);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> p_st;
        set<pair<int, int>> a_st;
        int m = heights.size();
        int n = heights[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    if (p_st.find({i, j}) == p_st.end()) {
                        dfs(heights, p_st, i, j);
                    }
                }
                if (i == m - 1 || j == n - 1) {
                    if (a_st.find({i, j}) == a_st.end()) {
                        dfs(heights, a_st, i, j);
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto it : p_st) {
            if (a_st.find(it) != a_st.end()) {
                result.push_back({it.first, it.second});
            }
        }

        return result;
    }
};