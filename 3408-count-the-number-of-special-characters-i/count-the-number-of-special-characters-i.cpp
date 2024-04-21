class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int count =0;
        set<char>s;
        for(int i =0;i<n;i++){
            s.insert(word[i]);
        }
        string f;
        for(auto it : s){
            f+=it;
        }
        int m  = f.size();
        for(int i = 0;i<m;i++){
            for(int j = 0 ; j<m ;j++){
                if(f[i]+32==f[j]){
                    count++;

                }
            }
        }
        return count;
    }
};