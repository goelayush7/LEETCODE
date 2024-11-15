class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int openbrack = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                openbrack++;
                ans = max(ans,openbrack);
            }
            else if(s[i]==')')openbrack--;
        }
        return ans;
    }
};