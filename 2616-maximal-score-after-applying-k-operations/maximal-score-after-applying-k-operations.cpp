class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long>pq;
        for(auto it : nums){
            pq.push(it);
        }
        while(k--){
            double val = pq.top();
            pq.pop();
            ans+=val;
            pq.push(ceil(val/3));
        }
        return ans;
    }
};