class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < pq.size(); i++) {
            int u = pq[i][0];
            int v = pq[i][1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < pq.size(); i++) {
            indegree[pq[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> vect;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            vect.push_back(front);
            for (auto it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return vect.size() == numCourses;
    }
};