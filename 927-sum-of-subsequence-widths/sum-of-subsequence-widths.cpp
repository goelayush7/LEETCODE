class Solution {
public:
    int mod = 1000000007;
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long>power(nums.size());
        power[0]=1;
        for(int i =1;i<nums.size();i++){
            power[i] = power[i-1]*2%mod;
        }
        long long count =0;
        for(int i =0;i<nums.size();i++){
            count = (count+(power[i]-power[n-i-1])*nums[i])%mod;
        }
        return (int)count;
    }
};