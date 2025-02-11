class Solution {
public:
    string removeOccurrences(string s, string part) {
        char last = part[part.size()-1];
        stack<char>st;
        for(int i =0;i<s.size();i++){
            st.push(s[i]);
            if(s[i]==last){
                string temp = "";
                while(!st.empty() && temp.size()!=part.size()){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(temp!=part){
                    for(int i  =0 ;i<temp.size();i++){
                        st.push(temp[i]);
                    }
                }
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};