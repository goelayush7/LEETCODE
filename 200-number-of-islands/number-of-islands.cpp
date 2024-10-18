class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i ,int j){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        for(int k =0;k<4;k++){
            int nrow = drow[k]+i;
            int ncol = dcol[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};