class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(queries.size(), -1);
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        vector<pair<int, int>> sq;
        for (int i = 0; i < queries.size(); i++) {
            sq.push_back({queries[i], i});
        }
        sort(sq.begin(), sq.end());
        int totalcount =0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        vis[0][0] =1;
        pq.push({grid[0][0],{0,0}});
        for(auto [number,index] : sq){

            while(!pq.empty() && pq.top().first<number){
                auto top = pq.top();
                pq.pop();
                int num = top.first;
                int row = top.second.first;
                int col = top.second.second;
                totalcount++;
                for(int i =0;i<4;i++){
                    int nrow = row+drow[i];
                    int ncol = col+dcol[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==-1){
                        pq.push({grid[nrow][ncol],{nrow,ncol}});
                        vis[nrow][ncol] =1;
                    }
                }
            }
            ans[index] = totalcount;
        }
        return ans;
    }

};