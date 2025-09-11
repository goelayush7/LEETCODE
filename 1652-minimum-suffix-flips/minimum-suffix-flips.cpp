class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        bool flag = true;
        for(auto it : target){
           if((flag==true && it=='1') || (flag==false && it=='0')){
            count++;
            flag = !flag;
           }
        }
        return count;
    }
};