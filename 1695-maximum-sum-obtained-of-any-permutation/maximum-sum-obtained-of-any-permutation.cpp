class Solution {
public:
    int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>temp(n+1,0);
        for(auto it : requests){
            int start = it[0];
            int end = it[1];
            temp[start]++;
            temp[end+1]--;
        }
        vector<int>temp1;
        int sum = 0;
        for(int i = 0;i<temp.size();i++){
            sum+=temp[i];
            temp1.push_back(sum);
        }
        sort(temp1.begin(),temp1.end());
        reverse(temp1.begin(),temp1.end());
        int end = nums.size()-1;
        long long ans = 0;
        for(auto it : temp1){
            if(it>0){
                ans = (ans + (1LL * it * nums[end]) % mod) % mod;
                end--;
            }
        }
        return ans%mod;
    }
};