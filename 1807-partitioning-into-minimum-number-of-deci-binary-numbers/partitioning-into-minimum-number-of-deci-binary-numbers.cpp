class Solution {
public:
    int minPartitions(string n) {
       int ans = 0;
       for(auto it : n){
            if(ans<it-'0'){
                ans = it-'0';
            }
       }
       return ans;
    }
};