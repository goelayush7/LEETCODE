class Solution {
public:
    int possibleStringCount(string word) {
        int count  = 0;
        int n = word.size();
        for(int i =1;i<n;i++){
            if(word[i]==word[i-1])count++;
        }
        return count+1;
    }
};