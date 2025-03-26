class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>temp;
        vector<int>temp2;
        for(int i = 0 ;i<m;i++){
            for(int j = 0 ;j<n;j++){
                temp2.push_back(grid[i][j]);
                temp.push_back(grid[i][j]%x);
            }
        }
        for(int i = 0;i<temp.size()-1;i++){
            if(temp[i]!=temp[i+1]){
                return -1;
            }
        }
        sort(temp2.begin(),temp2.end());
        int number = m*n;
        int middlenumber = temp2[(m*n)/2];
        int ans= 0 ;
        for(auto it : temp2){
            ans+=abs(it-middlenumber)/x;
        }
        return ans;
        

    }
};