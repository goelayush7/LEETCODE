class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        int n = nums.size();
        for(int i =0;i<n;i++){
            maps[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it:maps){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
        
    }
};