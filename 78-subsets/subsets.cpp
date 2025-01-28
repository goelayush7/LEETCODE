class Solution {
public:
    void subset(vector<int>&nums,int i,vector<vector<int>>&out,vector<int>ans){
        out.push_back(ans);
        for(int j = i;j<nums.size();j++){
            ans.push_back(nums[j]);
            subset(nums,j+1,out,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>out;
        vector<int>ans;
        subset(nums,0,out,ans);
        return out;
    }
};