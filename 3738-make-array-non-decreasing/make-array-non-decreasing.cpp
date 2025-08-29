class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        for(auto it :nums){
            if(st.empty() || st.top()<=it){
                st.push(it);
            }
        }
        return st.size();
    }
};