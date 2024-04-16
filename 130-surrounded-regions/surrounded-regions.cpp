class Solution {
public:
    void dfs(vector<vector<char>>& board , vector<vector<int>>& vis,int sr,int sc){
        vis[sr][sc]=1;
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        for(int i =0;i<4;i++){
            int nrow = sr+drow[i];
            int ncol = sc+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<m ; i++){
            if(board[0][i]=='O' && vis[0][i]==0){
                dfs(board,vis,0,i);
            }
        }
        for(int i =0;i<m ; i++){
            if(board[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(board,vis,n-1,i);
            }
        } 
        for(int i =0;i<n ; i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(board,vis,i,0);
            }
        }
         for(int i =0;i<n ; i++){
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(board,vis,i,m-1);
            }
        }  
        for(int i =0;i<n; i++){
            for(int j =0;j<m ; j++){
                if (vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};