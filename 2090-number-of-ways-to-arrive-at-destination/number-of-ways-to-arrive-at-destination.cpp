class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Build the adjacency list
        for (auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        // Min-heap to store (distance, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        
        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            
            if (distance > dis[node]) continue;
            
            for (auto [newnode, newdis] : adj[node]) {
                long long totalDistance = distance + newdis;
                
                if (totalDistance < dis[newnode]) {
                    dis[newnode] = totalDistance;
                    pq.push({totalDistance, newnode});
                    ways[newnode] = ways[node];
                } else if (totalDistance == dis[newnode]) {
                    ways[newnode] = (ways[newnode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
