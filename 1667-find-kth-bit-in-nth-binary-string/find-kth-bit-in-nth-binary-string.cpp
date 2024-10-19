class Solution {
public:
    string reverse(string s){
        string val="" ;
        int n = s.size();
        for(int i =n-1;i>=0 ;i--){
            val+=s[i];
        }
        return val;
    }
    string invert(string s){
        for(int i =0;i<s.size();i++){
            if(s[i]=='1')s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string start="0";
        while(n--){
            start = start + '1' + reverse(invert(start));
        }
        return start[k-1];
    }
};