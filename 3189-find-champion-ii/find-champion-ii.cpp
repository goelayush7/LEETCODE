class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto it : edges){
            indegree[it[1]]++;
        }
        int ans = 0;
        int count =0;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                count++;
                ans = i;
            }
        }
        if(count>1)return -1;
        return ans;
    }
};