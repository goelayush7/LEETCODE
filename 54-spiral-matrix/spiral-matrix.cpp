class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int sc = 0;
        int sr = 0;
        int ec = matrix[0].size()-1;
        int er = matrix.size()-1;
        while(sc<=ec && sr<=er){
            for(int i =sc;i<=ec;i++){
                ans.push_back(matrix[sr][i]);
            }
            sr++;
            for(int i = sr;i<=er;i++){
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            if(sr<=er){
                for(int i = ec;i>=sc;i--){
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }
            if(sc<=ec){
                for(int i = er;i>=sr;i--){
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return ans;
    }
};