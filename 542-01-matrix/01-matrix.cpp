class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,10000));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    vis[i][j] =1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int dis = front.second;
            q.pop();
            ans[row][col] = dis;
            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};
            for(int i =0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] ){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};