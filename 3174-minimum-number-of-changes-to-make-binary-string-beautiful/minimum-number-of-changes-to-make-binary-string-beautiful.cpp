class Solution {
public:
    int minChanges(string s) {
        int count  = 0;
        int i = 0;
        int n = s.size();
        while(i<n){
            if(s[i]!=s[i+1])count++;
            i = i+2;
        }
        return count;

    }
};