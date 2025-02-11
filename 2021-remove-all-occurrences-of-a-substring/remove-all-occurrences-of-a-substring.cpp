class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int partSize = part.size();
        
        for (char c : s) {
            st.push(c);

            // Check if the last 'partSize' characters in stack match 'part'
            if (st.size() >= partSize) {
                string temp = "";
                for (int i = 0; i < partSize; i++) {
                    temp = st.top() + temp;  // Construct the string correctly
                    st.pop();
                }
                
                if (temp != part) {
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }
            }
        }

        // Convert stack to result string
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
