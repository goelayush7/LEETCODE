class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>maps;
        for(auto it : arr){
            maps[it]++;
        }
        for(auto it: maps){
            pq.push({it.second,it.first});
        }
        int n = arr.size();
        int cpyn =n;
        int count = 0 ;
        while(cpyn>n/2){
            cpyn -= pq.top().first;
            pq.pop();
            count++;
        }
        return count;
    }
};