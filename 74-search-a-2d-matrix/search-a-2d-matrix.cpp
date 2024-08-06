class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m*n-1;
        while(start<=high){
            int mid = (start+high)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) high = mid-1;
            else start = mid+1;
        }
        return false;
        
    }
};