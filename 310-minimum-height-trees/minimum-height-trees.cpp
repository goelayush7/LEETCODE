class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        vector<int> deg(n, 0);
        vector<vector<int>> graph(n);
        queue<int> q;

        for (auto e : edges) {
            deg[e[0]]++;
            deg[e[1]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; ++i) {
                int ele = q.front();
                q.pop();
                for (auto it : graph[ele]) {
                    deg[it]--;
                    if (deg[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
