class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        unordered_map<int,int>maps;
        int ans = -1;
        while(!pq.empty()){
            int temp =-1;
            int val = pq.top();
            pq.pop();
            int sum = 0;
            int copy = val;
            while(val>0){
                sum+=val%10;
                val = val/10;
            }
            if(maps.find(sum)!=maps.end()){
                temp = maps[sum]+copy;
            }
            else maps[sum]=copy;
            ans = max(ans,temp);
        }
        return ans;
    }
};