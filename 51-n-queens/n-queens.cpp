class Solution {
public:
    bool issafe(vector<vector<string>>&ans,vector<string>&res,int n , int col,int row){
        int duprow = row;
        int dupcol = col;

        //check for upper diagnol
        while(row>=0 && col>=0){
            if(res[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col>=0){
            if(res[row][col]=='Q') return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0 ){
            if(res[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void helper(vector<vector<string>>&ans,vector<string>&res,int n,int col){
        if(col==n){
            ans.push_back(res);
            return;
        }
        for(int row = 0 ; row<n ; row++){
            if(issafe(ans,res,n,col,row)){
                res[row][col]='Q';
                helper(ans,res,n,col+1);
                res[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      helper(ans, board, n, 0);
      return ans;

    }
};