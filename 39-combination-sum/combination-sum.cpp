class Solution {
public:
    void helper(vector<int>& candidates, int target,int n,vector<int>&out,vector<vector<int>>&ans,int idx){
        if(target==0){
            sort(ans.begin(),ans.end());
            ans.push_back(out);
            return;
        }
        if(target<0 || idx<0){
            return;
        }
        //exclude;
        helper(candidates,target,n,out,ans,idx-1);
        //include;
        out.push_back(candidates[idx]);
        helper(candidates,target-candidates[idx],n,out,ans,idx);
        out.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>out;
        vector<vector<int>>ans;
        helper(candidates,target,candidates.size(),out,ans,candidates.size()-1);
        return ans;
    }
};