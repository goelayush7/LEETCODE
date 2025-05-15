class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char it : num) {
            while (!st.empty() && st.top() > it && k > 0) {
                st.pop();
                k--;
            }
            st.push(it);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        int i = 0;
        while (i < temp.size() && temp[i] == '0') {
            i++;
        }

        string result = temp.substr(i);
        return result.empty() ? "0" : result;
    }
};
