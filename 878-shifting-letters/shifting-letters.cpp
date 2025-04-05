class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int>prefix(s.size(),0);
        prefix[s.size()-1] = shifts[s.size()-1];
        for(int i = s.size()-2;i>=0;i--){
            prefix[i] =( shifts[i] + prefix[i+1])%26;
        }
        string ans = "";
        for(int i = 0 ;i < s.size(); i++){
            ans += char((s[i] - 'a' + prefix[i]) % 26 + 'a');
        }
        return ans;
    }
};