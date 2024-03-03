class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int count =0;
        while(minHeap.top()<k && minHeap.size()>1){
            int firstmin = minHeap.top();
            minHeap.pop();
            int secondmin = minHeap.top();
            minHeap.pop();
            long long res = (long long)min(firstmin,secondmin)*2 + max(firstmin,secondmin);
            minHeap.push(res);
            count++;
            

        }
        return count;
    }
};