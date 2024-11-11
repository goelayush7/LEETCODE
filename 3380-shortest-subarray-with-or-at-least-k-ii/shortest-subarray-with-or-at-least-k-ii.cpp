class Solution {
public:
    void updatebits(vector<int>&count,int num,int val){
        for(int i =0;i<32;i++){
            if(num&(1<<i))count[i]+=val;
        }
    }
    int getval(vector<int>&count){
        int ans =0;
        for(int i =0;i<32;i++){
            if(count[i]>0){
                ans|=(1<<i);
            }
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int start =0;
        int end = 0;
        int n = nums.size();
        vector<int>count(32,0);
        int ans =INT_MAX;
        while(end<n){
            updatebits(count,nums[end],1);
            while(start<=end && getval(count)>=k){
                ans = min(ans,end-start+1);
                updatebits(count,nums[start],-1);
                start++;
            }
            end++;
        }
        return ans==INT_MAX?-1:ans;
    }
};