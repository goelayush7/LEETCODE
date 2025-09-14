class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto it : s){
            if(st.empty()){
                st.push(it);
            }
            else{
                if((it==')' && st.top()=='(')){
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
        }
        return st.size();
    }
};