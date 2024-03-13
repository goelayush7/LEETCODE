class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>v;
        int i =0;
        int j =0;
        int n = nums.size();
        while(j<k){
            while(!q.empty() && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            j++;
        }
        v.push_back(q.front());
        while(j<n){
            if(nums[i]==q.front()) q.pop_front();
            i++;
            while(!q.empty() && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            j++;
            v.push_back(q.front());
         }
         return v;
    }
};