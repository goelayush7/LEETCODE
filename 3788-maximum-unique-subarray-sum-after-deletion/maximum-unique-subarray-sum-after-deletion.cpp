class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        bool flag = false;
        for (auto it : nums) {
            if (it > 0 && st.find(it) == st.end()) {
                sum += it;
                st.insert(it);
                flag = true;
            }
        }
        if(!flag)return *max_element(nums.begin(),nums.end());
        return sum;
    }
};