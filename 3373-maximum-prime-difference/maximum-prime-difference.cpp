class Solution {
public:
    bool isprime(int n){
         if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        for(int i =2; i<=n/2 ; i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i =0;i<n ; i++){
            if(isprime(nums[i])){
                ans.push_back(i);
            }
        }
        int n1 = ans.size();
        if(n1==1)return 0;
        return ans[n1-1]-ans[0];
    }
};