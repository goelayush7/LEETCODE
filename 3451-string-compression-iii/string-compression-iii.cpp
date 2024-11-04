class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i =0;
        int n = word.size();
        while(i<n){
            char c = word[i];
            int count =1;
            int j=i+1;
            while(word[j]==c && j<n && count<9){
                j++;
                count++;
            }
            comp+=to_string(count);
            comp+=c;
            i=j;
        }
        return comp;
    }
};