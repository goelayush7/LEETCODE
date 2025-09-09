class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int>indegree;
        map<string,vector<string>>adj;
        for(int i=0;i<ingredients.size();i++){
            for(auto it : ingredients[i]){
                adj[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto it : supplies){
            if(indegree[it]==0){
                q.push(it);
            }
        }
        vector<string>ans;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto it : adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};