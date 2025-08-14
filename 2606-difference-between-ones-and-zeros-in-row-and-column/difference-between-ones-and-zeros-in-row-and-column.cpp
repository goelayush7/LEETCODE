class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>row;
        vector<int>col;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            int countr = 0;
            for(int j = 0 ; j<m;j++){
                if(grid[i][j]==1)countr++;
            }
            row.push_back(countr);
        }
        for(int j=0;j<m;j++){
            int countf = 0;
            for(int i = 0 ;i<n;i++){
                if(grid[i][j]==1){
                    countf++;
                }
            }
            col.push_back(countf);
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                int orr = row[i];
                int oc = col[j];
                int zr = n-orr;
                int zc = m-oc;
                ans[i][j]= orr+oc-zr-zc;
            }
        }
        return ans;
    }
};