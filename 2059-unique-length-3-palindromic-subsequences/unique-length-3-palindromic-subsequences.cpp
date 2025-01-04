class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        unordered_set<char>ch;
        for(int i =0;i<s.size();i++){
            ch.insert(s[i]);
            int val = s[i] - 'a';
            if(first[val]==-1){
                first[val] = i;
            }
            last[val] = i;
        }
        int ans = 0;
        for(auto it : ch){
            unordered_set<char>bet;

            for(int k = first[it-'a']+1 ; k<last[it-'a'];k++){
                bet.insert(s[k]);
            }
            ans+=bet.size();
        }return ans;




    }
};