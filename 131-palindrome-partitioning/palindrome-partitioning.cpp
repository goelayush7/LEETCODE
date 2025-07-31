class Solution {
public:
    bool ispalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<string>&temp,vector<vector<string>>&out,int index){
        int n = s.size();
        if(index==n){
            out.push_back(temp);
            return;
        }
        for(int i = index;i<n;i++){
            if(ispalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                helper(s,temp,out,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>vect;
        vector<string>temp;

        helper(s,temp,vect,0);
        return vect;
    }
};