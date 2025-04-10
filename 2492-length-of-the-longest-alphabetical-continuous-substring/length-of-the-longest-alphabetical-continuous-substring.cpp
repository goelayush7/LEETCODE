class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count =1;
        int maxcount =1;
        for(int i = 1;i<s.size();i++){
            if(s[i-1]+1==s[i]){
                count++;
                maxcount = max(maxcount,count);
            }
            else count=1;
        }
        return maxcount;
    }
};