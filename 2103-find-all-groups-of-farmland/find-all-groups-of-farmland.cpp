class Solution {
public:
    void bfs(vector<vector<int>>& land ,vector<vector<int>>& vis,int row,int col,vector<vector<int>>&ans){
        vis[row][col] = 1;
        int n = land.size();
        int m = land[0].size();
        int startrow = row;
        int startcol = col;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && land[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
            if((r+1 > n-1 || land[r+1][col]==0) && (c+1 > m-1 || land[r][c+1]==0)){
                ans.push_back({startrow,startcol,r,c});
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();  
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j]==1 && !vis[i][j]){
                    bfs(land, vis, i, j, ans);
                }
            }
        }
        return ans;
    }
};
