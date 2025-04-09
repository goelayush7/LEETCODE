class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> vect(m*n+1);
        vector<int>x(m,0);
        vector<int>y(n,0);
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                int num = mat[i][j];
                vect[num] = {i,j};
            }
        }
        for(int i =0;i<m*n;i++){
            auto it = vect[arr[i]];
            int xc = it.first;
            int yc = it.second;
            x[xc]++;
            if(x[xc]==n)return i;
            y[yc]++;
            if(y[yc]==m)return i;
        }
        return -1;

        
        return -1;

    }
};