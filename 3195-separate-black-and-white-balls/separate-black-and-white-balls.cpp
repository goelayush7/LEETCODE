class Solution {
public:
    long long minimumSteps(string s) {
        int i =0;
        int j = s.size()-1;
        long long ans = 0;
        while(i<j){
            if(s[j]=='0' && s[i]=='1'){
                swap(s[j],s[i]);
                long long val = j-i;
                ans+=val;
                i++;
                j--;
            }
            else if (s[i]=='0')i++;
            else if (s[j]=='1')j--;
        }
        return ans;
        
    }
};