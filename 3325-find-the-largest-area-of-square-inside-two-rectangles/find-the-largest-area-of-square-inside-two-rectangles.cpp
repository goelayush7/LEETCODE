class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxi = 0;
        bool inter = false;
        int n = bottomLeft.size();
        int m = topRight.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1= max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1= max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2= min(topRight[i][0],   topRight[j][0]);
                int y2= min(topRight[i][1],   topRight[j][1]);
                
                if(x1<x2 && y1<y2){
                    inter = true;
                    long long side = min(x2-x1, y2-y1);
                    maxi = max(maxi, side*side);
                }
            }
        }
        if(!inter)
            return 0;
        return maxi;        
    }   
};