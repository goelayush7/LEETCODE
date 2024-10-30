class Solution {
public:
    int helper(vector<vector<int>>&grid,int row,int col,int prev,vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || row>=n || col>=m)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int down = 0;
        if(row-1>=0 && col+1<m && grid[row-1][col+1]>prev){
            int value = grid[row-1][col+1];
            down = 1+helper(grid,row-1,col+1,value,dp);
        }
        int up =0;
        if(row+1<n && col+1<m && grid[row+1][col+1]>prev){
            int value = grid[row+1][col+1];
            up = 1+helper(grid,row+1,col+1,value,dp);
        }
        int side = 0;
        if(col+1<m && grid[row][col+1]>prev){
            int value = grid[row][col+1];
            side = 1+helper(grid,row,col+1,value,dp);
        }
        return dp[row][col] = max(down,max(side,up));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<grid.size();i++){
            int temp = grid[i][0];
            int value = helper(grid,i,0,temp,dp);
            ans = max(ans,value);
        }
        return ans;
    }
};