class Solution {
public:
    void fun(vector<int>& candidates, int target, int i, vector<int>& out,
             vector<vector<int>>& ans, int n) {
        if(target==0){
            ans.push_back(out);
            return;
        }
        if(target<0 || i==n){
            return;
        }
        if(candidates[i]<=target){
            out.push_back(candidates[i]);
            fun(candidates,target-candidates[i],i,out,ans,n);
            out.pop_back();
        }
        fun(candidates,target,i+1,out,ans,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> ans;
        fun(candidates,target,0,out,ans,candidates.size());
        return ans;
    }
};