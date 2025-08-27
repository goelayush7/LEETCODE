class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq(nums.begin(),nums.end());
        int ans = 0;
        while(pq.top()<k && pq.size()>=2){
            ans++;
            long long val1 = pq.top();
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            long long mini = min(val1,val2);
            long long maxi = max(val1,val2);
            long long  final = mini*2 + maxi;
            pq.push(final);
        }
        return ans;
    }
};