class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
        int n = s.size();
        for(int i =1;i<n;i++){
            score+=abs(int(s[i])-int(s[i-1]));
        }
        return score;
        
    }
};