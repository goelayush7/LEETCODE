class Solution {
public:
    int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int>vect(n,1);
        while(k--){
            for(int i = 1;i<n;i++){
                vect[i] = vect[i]%mod+vect[i-1]%mod;
                vect[i] %= mod;
            }
        }
        return vect[n-1]%mod;
    }
};