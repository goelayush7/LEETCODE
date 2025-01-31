class Solution {
public:
    void combination(int k,int n,vector<vector<int>>&out,vector<int>ans,int start){
        if(ans.size()==k && n==0){
            out.push_back(ans);
            return;
        }
        //pick the element
        if(ans.size()>k || k<0 || start>9)return;
        ans.push_back(start);
        combination(k,n-start,out,ans,start+1);
        ans.pop_back();
        combination(k,n,out,ans,start+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int start = 1;
        vector<int>ans;
        vector<vector<int>>out;
        combination(k,n,out,ans,start);
        return out;
    }
};