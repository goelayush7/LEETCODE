class Solution {
public:
    int minimumLength(string s) {
        int i =0;
        int j = s.size()-1;
        while(i<j && s[i]==s[j]){
            char f = s[i];
            while(i<=j && s[i]==f) i++;
            while(j>=i && s[j] == f) j--;
        }
        return j-i+1;
    }
};