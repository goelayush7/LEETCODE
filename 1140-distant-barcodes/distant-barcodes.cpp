class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> maps;
        for (auto it : barcodes) {
            maps[it]++;
        }
        for (auto it : maps) {
            pq.push({it.second, it.first});
        }
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int val = top.second;
            int count = top.first;
            if (ans.empty() || ans.back() != val) {
                ans.push_back(val);
                if (count > 1) {
                    pq.push({count-1, val});
                }
            }
            else{
                if (pq.empty()) break;
                auto newtop = pq.top();
                pq.pop();
                int newval = newtop.second;
                int newcount = newtop.first;
                ans.push_back(newval);
                if(newcount>1){
                    pq.push({newcount-1,newval});
                }
                pq.push({count,val});
            }
        }
        return ans;
    }
};