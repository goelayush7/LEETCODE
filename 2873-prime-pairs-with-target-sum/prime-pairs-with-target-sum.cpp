class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>prime(n+1,true);
        for(int p = 2;p*p<=n;p++){
            if(prime[p]==true){
                for(int i = p*p ; i<=n ; i+=p){
                    prime[i] = false;
                }
            }
        }
        unordered_set<int>st;
        for(int i =2;i<prime.size();i++){
            if(prime[i]==true){
                st.insert(i);
            }
        }
        vector<vector<int>>temp;
        for(int i = 1 ; i <= n/2;i++){
            if(st.find(i)!=st.end() && st.find(n-i)!=st.end()){
                temp.push_back({i,n-i});
            }
        }
        return temp;
    }
};