class Solution {
public:
    void helper(vector<int>&candidates,int target,int i,vector<int>ans,vector<vector<int>>&out){
        if(target==0){
            sort(ans.begin(),ans.end());
            out.push_back(ans);
            return;
        }
        if(i<0 || target<0){
            return;
        }
        //exclude;
        helper(candidates,target,i-1,ans,out);
        //include;
        ans.push_back(candidates[i]);
        helper(candidates,target-candidates[i],i,ans,out);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>out;
        helper(candidates,target,candidates.size()-1,ans,out);
        return out;
    }
};