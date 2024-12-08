class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        sort(events.begin(), events.end());
        int ans = 0;
        int maxval = 0;
        for(auto& event:events){
            while(pq.size() && pq.top().first<event[0]){
                maxval = max(maxval,pq.top().second);
                pq.pop();
            }
            ans = max(ans,event[2]+maxval);
            pq.push({event[1],event[2]});
        }
        return ans;
    }
};