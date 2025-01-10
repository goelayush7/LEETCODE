class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i =0;i<n;i++){
            char a = s[0];
            s = s.substr(1,goal.size())+a;
            if(s==goal)return true;
        }
        return false;
    }
};