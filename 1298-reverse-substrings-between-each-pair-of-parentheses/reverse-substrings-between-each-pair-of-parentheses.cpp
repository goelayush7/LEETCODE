class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans;
        for (auto it : s) {
            if (it == ')') {
                while (st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            for(auto it1 : ans){
                st.push(it1);
            }
            ans.clear();
            if(it!=')')st.push(it);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};