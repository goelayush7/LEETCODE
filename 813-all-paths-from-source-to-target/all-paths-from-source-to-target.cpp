class Solution {
public:
    void dfs(vector<int> adj[], int source, int target, vector<int>& temp,
             vector<vector<int>>& out) {
        if (source == target) {
            out.push_back(temp);
            return;
        }

        for (auto it : adj[source]) {
            temp.push_back(it);
            dfs(adj, it, target, temp, out);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[15];
        for (int i = 0; i < graph.size(); i++) {
            for (auto it : graph[i]) {
                adj[i].push_back(it);
            }
        }
        vector<vector<int>> out;
        vector<int> temp;
        temp.push_back(0);
        dfs(adj, 0, n - 1, temp, out);
        return out;
    }
};