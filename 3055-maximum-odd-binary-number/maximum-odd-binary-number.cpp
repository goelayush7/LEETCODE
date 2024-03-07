class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        for(int i =0;i<n ; i++){
            if(s[i]=='1'){
                swap(s[i],s[n-1]);
            }
        }
        sort(s.begin(),s.end()-1);
        reverse(s.begin(),s.end()-1);
        return s;
    }
};