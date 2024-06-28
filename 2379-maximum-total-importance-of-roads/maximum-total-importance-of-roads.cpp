class Solution {
public:
static bool cmp(pair<int,int> &a,pair<int,int>&b)
    {
        return a.first>b.first;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        map<int, int> degree;
        for (auto road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        vector<pair<int, int>> degreeNodePairs;
        for (auto it : degree) {
            degreeNodePairs.push_back({it.second, it.first});
        }
        sort(degreeNodePairs.begin(), degreeNodePairs.end(),cmp);
        vector<int> nodeValues(n, 0);
        int value = n;
        for (auto pair : degreeNodePairs) {
            nodeValues[pair.second] = value--;
        }
        for (auto road : roads) {
            ans += nodeValues[road[0]] + nodeValues[road[1]];
        }
        return ans;
    }
};