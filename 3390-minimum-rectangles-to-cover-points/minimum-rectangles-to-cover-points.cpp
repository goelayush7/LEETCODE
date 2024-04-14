class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int ans =0;
        int n = points.size();
        int i =0;
        while(i<n){
            ans++;
            int smallest = points[i][0];
            for(int j =i ;j<n;j++){
                if(points[j][0]==smallest || smallest+w>=points[j][0]) i++;
                else break;
            }
        }
        return ans;
    }
};