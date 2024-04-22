class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        std::unordered_map<char, int> maps;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if(int(word[i])>=65 && int(word[i])<=90){
                if(maps.find(word[i])==maps.end()){
                    maps[word[i]]=i;
                }
            }
            if(int(word[i])>=97 && int(word[i])<=122){
                maps[word[i]]=i;
            }
        }
        std::set<char> s;
        for (int i = 0; i < n; i++) {
            s.insert(word[i]);
        }
        std::string f;
        for (auto it : s) {
            f += it;
        }
        int m = f.size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            char target = f[i] - 32;
            if (maps.find(target) != maps.end()) {
                if (maps[f[i]] < maps[target]) {
                    count++;
                }
            }
        }
        return count;
    }
};