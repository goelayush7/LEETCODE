class Solution {
public:
    string removeOuterParentheses(string s) {
        int startcount =0;
        string ans ="";
        string temp = "";
        for(int i =0;i<s.size();i++){
            temp+=s[i];
            if(s[i]=='('){
                startcount++;
            }
            else if(s[i]==')'){
                startcount--;
            }
            if(startcount==0){
                int n = temp.size();
                ans+=temp.substr(1,n-2);
                temp = "";
            }
        }
        return ans;
    }
};