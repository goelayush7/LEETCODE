class Solution {
public:
    int helper(map<int,int>maps,int x){
        priority_queue<pair<int,int>>pq;
        for(auto it:maps){
            pq.push({it.second,it.first});
        }
        int temp =0;
        int sum = 0;
        while(temp<x && !pq.empty()){
            int cnt = pq.top().first;
            int cntval = pq.top().second;
            pq.pop();
            sum+=cnt*cntval;
            temp++;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int i =0;
        int n = nums.size();
        map<int,int>maps;
        for(i=0;i<k;i++){
            maps[nums[i]]++;
        }
        int val = helper(maps,x);
        ans.push_back(val);
        for(int i = 1;i<=n-k;i++){
            maps[nums[i-1]]--;
            if(maps[nums[i-1]]==0){
                maps.erase(nums[i-1]);
            }
            maps[nums[i+k-1]]++;
            int val = helper(maps,x);
        ans.push_back(val);

        }
        return ans;
    }
};