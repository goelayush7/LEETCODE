class Solution {
public:
    int minimumDeletions(string s) {
        int count =0;
        int res= 0;
        for(auto c : s){
            if(c=='b'){
                count++;
            }
            else if(count){
                res++;
                count--;
            }

        }
        return res;
        
    }
};