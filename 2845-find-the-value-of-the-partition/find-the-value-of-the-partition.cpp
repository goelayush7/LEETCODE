class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = INT_MAX;
        for(int i =1;i<n;i++){
            mini = min(mini,abs(nums[i]-nums[i-1]));
        }
        return mini;
    }
};