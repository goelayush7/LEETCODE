class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>column;
        unordered_map<int,int>row;
        unordered_map<int,pair<int,int>>pos;
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                pos[mat[i][j]] = {i,j};
            }
        }
        for(int i =0;i<arr.size();i++){
            int val = arr[i];
            auto it  = pos[val];
            int r = it.first;
            int c = it.second;
            row[r]++;
            if(row[r]==m)return i;
            column[c]++;
            if(column[c]==n)return i;
    }
    return -1;
    }
};