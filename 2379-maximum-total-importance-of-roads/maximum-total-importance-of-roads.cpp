class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int>&b)
    {
        return a.first>b.first;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        map<int,int>maps;
       for (auto road : roads) {
            maps[road[0]]++;
            maps[road[1]]++;
        }

       vector<pair<int,int>>cpy;
       for(auto it : maps){
        cpy.push_back({it.second,it.first});
       }
       sort(cpy.begin(),cpy.end(),cmp);
       vector<int>val(n,-1);
       int maxi  =n;
       for(int i =0;i<cpy.size();i++){
            int index = cpy[i].second;
            val[index]=maxi;
            maxi--;
       }
       for(int i =0;i<roads.size();i++){
            int index1 = roads[i][0];
            int index2 = roads[i][1];
            ans+=val[index1]+val[index2];
       }
       return ans;
    }
};