class Solution {
public:
    bool check (int start,vector<vector<int>>&graph,vector<int>&vis){
     int n = graph.size();
      queue<int>q;
      q.push(start);
      if(q.empty()){
        q.push(start);
        vis[start]=0;
      }
      while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto s : graph[node]){
            if(vis[s]==-1){
                vis[s] = !vis[node];
                q.push(s);
            }
            else{
                if(vis[s]==vis[node]) return false;
            }
        }
      }
      return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        for(int i =0;i<n;i++){
            if(vis[i]==-1){
                if(check(i,graph,vis)==false)return false;
            }
        }
        return true;
    }
};