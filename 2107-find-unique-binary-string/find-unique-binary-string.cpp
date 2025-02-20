class Solution {
public:
    bool helper(vector<string>& nums, string &ans, const unordered_set<string>& st) {
        if (ans.size() == nums[0].size()) {
            return st.find(ans) == st.end(); 
        }

        for (char c : {'0', '1'}) {
            ans.push_back(c);
            if (helper(nums, ans, st)) return true;
            ans.pop_back(); 
        }
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string ans;
        helper(nums, ans, st);
        return ans;
    }
};
