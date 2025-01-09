class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int count =0;
        for(auto word:words){
            string str = word.substr(0,n);
            if(str==pref)count++;
        }
        return count;
    }
};