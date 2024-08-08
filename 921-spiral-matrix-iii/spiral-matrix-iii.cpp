class Solution {
public:
    bool issafe(int x,int y,int n,int m){
        if(x<0 || y<0 ||x>=n || y>=m) return false;
        return true;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans{{rStart,cStart}};
        int len =1;
        int size = rows*cols;
        int x = rStart;
        int y = cStart;
        while(ans.size()<size){
            for(int i = 1;i<=len;i++){
                if(issafe(x,y+i,rows,cols)){
                    ans.push_back({x,y+i});
                }
            }
            y+=len;
            for(int i =1;i<=len;i++){
                if(issafe(x+i,y,rows,cols)){
                    ans.push_back({x+i,y});
                }
            }
            x+=len;
            len++;
            for(int i = 1;i<=len;i++){
                if(issafe(x,y-i,rows,cols)){
                    ans.push_back({x,y-i});
                }
            }
            y-=len;
            for(int i =1;i<=len;i++){
                if(issafe(x-i,y,rows,cols)){
                    ans.push_back({x-i,y});
                }
            }
            x-=len;
            len++;
        }
        return ans;
    }
};