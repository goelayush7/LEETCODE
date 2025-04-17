class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>maxi;
        int n = nums.size();
        long long start = nums[0];
        maxi.push_back(start);
        for(int i =1;i<nums.size();i++){
            start = max(start,(long long)nums[i]);
            maxi.push_back(start);
        }
        vector<long long>vect(n,0);
        for(int i =0;i<n;i++){
            vect[i] = nums[i] + maxi[i];
        }
        vector<long long>ans;
        long long sum = 0;
        for(int i =0;i<n;i++){
            sum+=vect[i];
            ans.push_back(sum);
        }
        return ans;
    }
};