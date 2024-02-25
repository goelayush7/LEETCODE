class Solution {
public:
    void fun(vector<int>& nums,vector<int>&out, vector<vector<int>>&res,int i){
        res.push_back(out);
        for(int idx = i ; idx<nums.size(); idx++){
            if(idx>i && nums[idx]==nums[idx-1])continue;
            out.push_back(nums[idx]);
            fun(nums,out,res,idx+1);
            out.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>out;
                sort(nums.begin(),nums.end()); 

        fun(nums,out,res,0);

        sort(res.begin(),res.end());
        return res;
    }   
};