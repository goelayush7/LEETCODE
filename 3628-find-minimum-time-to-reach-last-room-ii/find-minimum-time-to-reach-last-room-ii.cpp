class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        using T = tuple<int, int, int>; // dis, row, col
        priority_queue<T, vector<T>, greater<T>> pq;

        int n = mt.size(), m = mt[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [dis, row, col] = pq.top(); pq.pop();
            if (dis > dist[row][col]) continue;

            int step = (row + col) % 2 + 1;

            for (int i = 0; i < 4; ++i) {
                int nr = row + drow[i], nc = col + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newDis = max(dis, mt[nr][nc]) + step;
                    if (newDis < dist[nr][nc]) {
                        dist[nr][nc] = newDis;
                        pq.push({newDis, nr, nc});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
