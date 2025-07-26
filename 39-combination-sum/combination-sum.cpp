class Solution {
public:
    void helper(vector<int>&cand,int target,int index,vector<int>&temp,vector<vector<int>>&out){
        if(target==0){
            out.push_back(temp);
            return;
        }
        if(index==cand.size()){
            if(target==0){
                out.push_back(temp);
            }
            return;
        }
        if(cand[index]<=target){
            temp.push_back(cand[index]);
            helper(cand,target-cand[index],index,temp,out);
            temp.pop_back();
        }
        helper(cand,target,index+1,temp,out);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>out;
        helper(candidates,target,0,temp,out);
        sort(out.begin(),out.end());
        return out;
    }
};