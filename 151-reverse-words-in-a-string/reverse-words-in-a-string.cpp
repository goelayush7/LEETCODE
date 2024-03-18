class Solution {
public:
    string reverseWords(string s) {
        stack<string>s1;
        int n = s.size();
        for(int i =0;i<n;i++){
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) {
                break;
            }
            string dummy="";

            while(s[i]!=' ' && i<n){
                dummy+=s[i];
                i++;
            }
            s1.push(dummy);
        }
        string ans="";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
            ans+=" ";
        }
        
        return ans.substr(0,ans.size()-1);
    }
};