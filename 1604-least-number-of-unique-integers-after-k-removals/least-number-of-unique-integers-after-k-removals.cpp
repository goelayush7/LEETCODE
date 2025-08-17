class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int>maps;
        for(auto it : arr){
            maps[it]++;
        }
        for(auto it : maps){
            pq.push({it.second,it.first});
        }
        while(k--){
            auto top = pq.top();
            pq.pop();
            int second = top.second;
            int first = top.first;
            first--;
            if(first>0){
                pq.push({first,second});
            }
        }
        return pq.size();

    }
};