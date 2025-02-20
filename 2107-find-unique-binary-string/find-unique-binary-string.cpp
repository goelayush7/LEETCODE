class Solution {
public:
    bool helper(vector<string>&nums,string &ans,unordered_set<string>st){
        if(ans.size()==nums[0].size()){
            if(st.find(ans)==st.end()){
                return true;
            }
            return false;
        }
        //add one
        ans.push_back('1');
        if(helper(nums,ans,st))return true;
        ans.pop_back();
        ans.push_back('0');
        if(helper(nums,ans,st))return true;
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string temp = "1";
        unordered_set<string>st(nums.begin(),nums.end());
        if(helper(nums,temp,st))return temp;
        temp ="0";
        if(helper(nums,temp,st))return temp;
        return temp;
        
    }
};