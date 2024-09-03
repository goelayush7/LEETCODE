class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string total;
        for(int i =0;i<n;i++){
            int val = s[i]-'a'+1;
            total+=to_string(val);
        }
        int ans = 0;
        while(k>0){
            int value = 0;
            for(int i =0;i<total.size();i++){
                value+=int(total[i])-48;
            }
            total = to_string(value);
            ans=value;
            k--;
        }
        return ans;

        
    }
};