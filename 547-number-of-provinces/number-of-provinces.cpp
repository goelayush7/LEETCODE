class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&vis,int i){
        vis[i] = true;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }
        return ans;
    }
};