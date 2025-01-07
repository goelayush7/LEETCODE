class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>st(words.begin(),words.end());
        set<string>ans;
        for(auto word:words){
            int n = word.size();
            for(int i =0;i<n;i++){
                for(int j = i+1;j<=n;j++){
                    string s = word.substr(i,j-i);
                    if(s!=word){
                        if(st.find(s)!=st.end()){
                            ans.insert(s);
                        }
                    }
                }
            }
        }
        vector<string>finaly;
        for(auto it : ans){
            finaly.push_back(it);
        }
        return finaly;
    }
};