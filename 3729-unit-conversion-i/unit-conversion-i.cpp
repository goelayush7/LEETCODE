class Solution {
public:
    int mod = 1e9 + 7;
    
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int maxNode = 0;
        for (auto& c : conversions) {
            maxNode = max({maxNode, c[0], c[1]});
        }

        vector<vector<pair<int, int>>> adj(maxNode + 1);
        for (auto& it : conversions) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<int> ans(maxNode + 1, -1);
        vector<bool> visited(maxNode + 1, false);

        queue<pair<int, int>> q;
        q.push({0, 1}); 
        visited[0] = true;
        ans[0] = 1;

        while (!q.empty()) {
            auto [node, curVal] = q.front();
            q.pop();

            for (auto& [nbr, wt] : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    ans[nbr] = (1LL * curVal * wt) % mod;
                    q.push({nbr, ans[nbr]});
                }
            }
        }

        return ans;
    }
};
