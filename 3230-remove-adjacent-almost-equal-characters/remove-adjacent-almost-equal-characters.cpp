class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count =0;
        int n = word.size();
        int i =0;
        while(i<n){
            if(word[i]==word[i+1] || word[i]==word[i+1]-1 || word[i]==word[i+1]+1){
                cout<<i<<endl;
                 
                count+=1;
                i+=2;
            }
            else i+=1;
        }
        return count;
    }
};