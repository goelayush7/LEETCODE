class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto flight : times){
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});
        vector<int>dis(n+1,INT_MAX);
        dis[k]= 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int node = top.second;
            for(auto it : adjList[node]){
                int tonode = it.first;
                int totime = it.second;
                if(time+totime<dis[tonode]){
                    dis[tonode] = time+totime;
                    pq.push({time+totime,tonode});
                }
            }
        }
        int ans= 0 ;
        for(int i =1;i<=n;i++){
            if(dis[i]==INT_MAX)return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};