#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxprofit = 0;
        vector<pair<int, int>> diffprof;
        
        // Combine difficulty and profit into a vector of pairs
        for (int i = 0; i < profit.size(); ++i) {
            diffprof.push_back({difficulty[i], profit[i]});
        }
        
        // Sort the diffprof by difficulty, then by profit
        sort(diffprof.begin(), diffprof.end());
        
        // Sort workers to ease the process of finding the best job they can do
        sort(worker.begin(), worker.end());
        
        int j = 0, best = 0;
        
        // Traverse each worker to find the maximum profit they can get
        for (int i = 0; i < worker.size(); ++i) {
            while (j < diffprof.size() && worker[i] >= diffprof[j].first) {
                best = max(best, diffprof[j].second);
                ++j;
            }
            maxprofit += best;
        }
        
        return maxprofit;
    }
};
