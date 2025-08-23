class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size()-1;
        for(int i = n;i>=0;i--){
            st.push(s[i]);
            if(st.top()=='a'){
                st.pop();
                if(st.size()<2)return false;
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                if(a!='b' || b !='c')return false;
            }
        }
        return st.empty();
    }
};