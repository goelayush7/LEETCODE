class Solution {
public:
    bool palidrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void part(string s,vector<string>ans,vector<vector<string>>&out,int start){
        if(start==s.size()){
            out.push_back(ans);
            return;
        }

        for(int index = start;index<s.size();index++){
            if(palidrome(s,start,index)){
                ans.push_back(s.substr(start,index-start+1));
                part(s,ans,out,index+1);
                ans.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>out;
        part(s,ans,out,0);
        return out;
    }
};