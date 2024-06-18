class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int maxprofit = 0;
        vector<pair<int,int>>diff;
        for (int i = 0; i < profit.size(); i++) {
            diff.push_back({difficulty[i], profit[i]});
        }
        int best = 0;
        sort(diff.begin(),diff.end());
        sort(worker.begin(),worker.end());
        for (int i = 0; i < worker.size(); i++) {
            int j = 0;
            while (j<profit.size() && worker[i]>=diff[j].first){
                best = max(best,diff[j].second);
                j++;
            }
            maxprofit+=best;
        }
        return maxprofit;
    }
};