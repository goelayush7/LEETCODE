class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int step = 0;
        for(int i = 0 ; i < s.size();i++){
            if(step<spaces.size() && i==spaces[step]){
                ans+=" ";
                step++;
            }
            ans+=s[i];
        }
        return ans;
    }
};