class Solution {
public:
    void helper(vector<int>&candidates,int target,vector<int>&out,vector<vector<int>>&ans,int idx){
       if(target==0){
           ans.push_back(out);
           return;
       }
       for(int i = idx ; i<candidates.size(); i++){
            if(candidates[i] > target) break; 
           if(i>idx && candidates[i]==candidates[i-1])continue;
           out.push_back(candidates[i]);
           helper(candidates,target-candidates[i],out,ans,i+1);;
           out.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>out;
        vector<vector<int>>ans;
        helper(candidates,target,out,ans,0);
        return ans;
        
    }
};