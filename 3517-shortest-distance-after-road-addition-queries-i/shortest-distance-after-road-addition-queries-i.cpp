#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Create adjacency list for the graph
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1); // Initialize with edges to next node
        }

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v); // Add the query edge to the graph

            // Perform BFS to find the shortest path from node 0 to node n-1
            vector<int> vis(n, 0);
            queue<pair<int, int>> q; // Pair: (node, distance from source)
            q.push({0, 0});
            vis[0] = 1;
            bool found = false;

            while (!q.empty()) {
                auto [front, dist] = q.front();
                q.pop();

                // If we reach the target node
                if (front == n - 1) {
                    ans.push_back(dist);
                    found = true;
                    break;
                }

                // Traverse neighbors
                for (int neighbor : adj[front]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push({neighbor, dist + 1});
                    }
                }
            }

            // If target node is unreachable, add -1 to the result
            if (!found) {
                ans.push_back(-1);
            }

            // Reset the graph to its initial state after each query
        }

        return ans;
    }
};
