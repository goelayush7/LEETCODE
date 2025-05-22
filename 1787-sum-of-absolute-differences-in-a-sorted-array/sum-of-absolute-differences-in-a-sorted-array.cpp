class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0);
        for(int i = 1;i<nums.size();i++){
            left[i] = left[i-1]+nums[i-1];
        }
        vector<int>right(n,0);
        for(int i =n-2;i>=0;i--){
            right[i] = right[i+1] + nums[i+1];
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int sumleft = left[i];
            int rightsum = right[i];
            int value = ((i*nums[i])-sumleft) + (rightsum - (n-i-1)*nums[i]);
            ans.push_back(value);
        }
        return ans;

    }
};