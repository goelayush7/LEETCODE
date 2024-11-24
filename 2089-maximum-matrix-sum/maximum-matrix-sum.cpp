class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum =0;
        int cn = 0;
        int smal =INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]<0)cn++;
                sum+=abs(matrix[i][j]);
                smal = min(smal,abs(matrix[i][j]));
            }
        }
        if(cn%2==0)return sum;
        else return sum-2*smal;
        
    }
};