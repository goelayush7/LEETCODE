class Solution {
public:
    int dfs(vector<vector<int>>grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        int temp =grid[row][col];
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        for(int i =0;i<4;i++){
            int nrow = drow[i]+row;
            int ncol = dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]!=0){
                temp+=dfs(grid,nrow,ncol,vis);
            }
        }
        return temp;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<int>ans;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fin = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    int val = dfs(grid,i,j,vis);
                    fin = max(fin,val);
                }
            }
        }
        return fin;
    }
};