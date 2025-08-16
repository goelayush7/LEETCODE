class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i =0 ;
        int j = 0 ; 
        string merge = "";
        while(i<n && j<m){
            if(word1[i] > word2[j]){
                merge+=word1[i];
                i++;
            }
            else if(word1[i]<word2[j]){
                merge+=word2[j];
                j++;
            }
            else{
                if(word1.substr(i+1)>word2.substr(j+1)){
                    merge+=word1[i];
                    i++;
                }
                else{
                    merge+=word2[j];
                    j++;
                }
            }
        }
        while(i<n){
            merge+=word1[i];
            i++;
        }
        while(j<m){
            merge+=word2[j];
            j++;
        }
        return merge;
    }
};