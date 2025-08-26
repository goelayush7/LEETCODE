class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count = 0 ;
        for(int i = 0;i<points.size()-1;i++){
            int value = points[i+1][0]-points[i][0];
            count = max(count,value);
        }
        return count;
    }
};