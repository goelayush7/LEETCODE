class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int right =1;
        int curcount =1;
        int n = nums.size();
        vector<int>ans;
        while(right<k){
            if(nums[right-1]+1==nums[right])curcount++;
            else curcount=1;
            right++;
        }
        if(curcount==k)ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        while(right<n){
            if(nums[right-1]+1==nums[right])curcount++;
            else curcount=1;
            if(curcount>=k && right>=k){
                ans.push_back(nums[right]);
            }
            else{
                ans.push_back(-1);
            }
            right++;
        }
        return ans;
    }
};