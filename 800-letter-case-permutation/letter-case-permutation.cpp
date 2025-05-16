class Solution {
public:
    void helper(string s,string temp,int index,set<string>&out){
        if(index==s.size()){
            out.insert(temp);
            return;
        }
        helper(s,temp+s[index],index+1,out);

        if(s[index]>='a' && s[index]<='z'){
            helper(s, temp + (char)toupper(s[index]), index + 1, out);
        }
        else{
            helper(s, temp + (char)tolower(s[index]), index + 1, out);
        }
    }
    vector<string> letterCasePermutation(string s) {
        set<string>ans;
        string temp;
        helper(s,temp,0,ans);
        vector<string>out;
        for(auto it : ans){
            out.push_back(it);
        }
        return out;
    }
};