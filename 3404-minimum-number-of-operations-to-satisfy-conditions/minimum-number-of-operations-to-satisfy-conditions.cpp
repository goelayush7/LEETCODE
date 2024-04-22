class Solution {
public:
    int solve(int j , int keep, vector<vector<int>>&dp, vector<vector<int>>& grid){
        int n = grid.size();
        int m= grid[0].size();
        //base case here we check if we have iterated over all the columns
        if(j >= m) return 0;
        if(dp[j][keep] != -1) return dp[j][keep];
        //iterate over the column to find the cost to change the values of column to keep
        int cost = 0;
        for(int i = 0; i < n; i++){
            if(grid[i][j] != keep) cost++;
        }
        int mincost = INT_MAX;
        //take account of minimum cost
        for(int digit = 0 ; digit <= 9 ; digit++ ){
            if(digit==keep)continue;
            mincost = min(mincost , cost+solve(j+1,digit,dp,grid));
        }
        return dp[j][keep] = mincost;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(10, -1)); // Changed the dimension of dp to [m][10]
        for(int keep = 0; keep <= 9 ; keep++){
            ans = min(ans, solve(0, keep, dp, grid));
        }
        return ans;
    }
};
