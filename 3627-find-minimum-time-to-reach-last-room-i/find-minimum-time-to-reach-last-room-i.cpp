class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9+1000));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({0, 0, 0}); // curvalue row col;
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int curvalu = front[0];
            int row = front[1];
            int col = front[2];
            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newd = max(curvalu,moveTime[nrow][ncol])+1;
                    if (dis[nrow][ncol] > newd) {
                        dis[nrow][ncol] = newd;
                        pq.push({newd, nrow, ncol});
                    }
                }
            }
        }
            return dis[n-1][m-1];

    }
};