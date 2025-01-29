class Solution {
public:
    void combination(vector<int>&candidates,int target,int i,vector<vector<int>>&out,vector<int>ans){
        int n = candidates.size();
        if(i>=n || target<0)return;
        if(target==0){
            out.push_back(ans);
            return;
        }
            ans.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i,out,ans);
            ans.pop_back();
            
            combination(candidates,target,i+1,out,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>out;
        vector<int>ans;
        combination(candidates,target,0,out,ans);
        return out;
    }
};