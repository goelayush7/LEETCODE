class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>row(m,-1);
        vector<int>col(n,-1);
        for(int i = 0;i<n;i++){
            int value = 0;
            for(int j = 0 ; j<m;j++){
                value = max(value,grid[i][j]);
            }
            row[i] =value;
        }
        for(int j = 0 ; j < m; j++){
            int value = 0;
            for(int i =0 ; i<n;i++){
                value = max(value,grid[i][j]);
            }
            col[j] = value;
        }
        int ans = 0 ;
        for(int i = 0 ; i <n;i++){
            for(int j = 0 ; j <m;j++){
                int reqvalue = min(row[i],col[j]);
                ans+=reqvalue-grid[i][j];
            }
        }
        return ans;
    }
};