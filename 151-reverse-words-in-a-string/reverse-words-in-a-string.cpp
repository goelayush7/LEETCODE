class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        vector<string>ans;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i>=n)break;
            string temp ="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            } 
            ans.push_back(temp);
        }
        string ans1;
        int n1 = ans.size()-1;
        ans1+=ans[n1];
        if(n1>0)ans1+=' ';
        while(n1--){
            ans1+=ans[n1];
            if(n1>0)ans1+=' ';
        }
        return ans1;
    }
};