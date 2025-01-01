class Solution {
public:
    int maxScore(string s) {
        int onecount =0;
        int zerocount = 0;
        for(auto it : s){
            if(it=='1')onecount++;
        }
        int ans = 0;
        for(int i =0;i<s.size()-1;i++){
            if(s[i]=='0')zerocount++;
            else if(s[i]=='1')onecount--;
            ans = max(ans,zerocount+onecount);
        }
        return ans;
    }
};