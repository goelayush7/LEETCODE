class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char it : expression) {
            if (it != ')') {
                st.push(it);
            } else {
                vector<bool> v;
                
                // Pop until we find the opening parenthesis '('
                while (st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if (t == 'f') {
                        v.push_back(false);
                    } else if (t == 't') {
                        v.push_back(true);
                    }
                }
                
                // Pop the opening parenthesis '('
                st.pop();
                
                // Pop the operator '&', '|', or '!'
                char oper = st.top();
                st.pop();
                
                bool val = (oper == '&') ? true : false;  // Initialize based on the operator
                if (oper == '&') {
                    for (bool it1 : v) {
                        val = val & it1;
                    }
                } else if (oper == '|') {
                    for (bool it1 : v) {
                        val = val | it1;
                    }
                } else if (oper == '!') {  // Negation only needs to negate the first element
                    val = !v[0];
                }
                
                // Push the result of the expression back to the stack
                st.push(val ? 't' : 'f');
            }
        }
        
        // The final result will be on the top of the stack
        return (st.top() == 't');
    }
};
