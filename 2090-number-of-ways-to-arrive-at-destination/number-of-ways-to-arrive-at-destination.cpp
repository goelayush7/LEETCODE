class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> steps(n, 0);
        vector<long long> dis(n, LLONG_MAX); // Fixed to long long
        dis[0] = 0;
        steps[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();
            
            if (weight > dis[node]) continue;

            for (auto& it : adj[node]) {
                int newnode = it.first;
                int newwt = it.second;

                // Update if the new distance is shorter
                if (dis[newnode] > weight + newwt) {
                    dis[newnode] = weight + newwt;
                    steps[newnode] = steps[node];
                    pq.push({dis[newnode], newnode});
                }
                // If the distance is the same, add the number of ways
                else if (dis[newnode] == weight + newwt) {
                    steps[newnode] = (steps[newnode] + steps[node]) % MOD;
                }
            }
        }

        return steps[n - 1];
    }
};
