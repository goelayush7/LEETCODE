class Solution {
public:
    bool check(vector<int>&nums,int maxop,int mid){
        int total = 0;
        for(auto num : nums){
            int ops = num/mid;
            if(num%mid==0)ops--;
            total +=ops;
        }
        return total<=maxop;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start  =1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end ;
        while(start<=end){
            int mid =(start+end)/2;
            if(check(nums,maxOperations,mid)){
                ans = min(mid,ans);
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};