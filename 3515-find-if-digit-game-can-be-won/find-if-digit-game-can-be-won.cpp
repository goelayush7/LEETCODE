class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singledigit = 0;
        int doubledigit = 0;
        for(auto num:nums){
            if(num<10){
                singledigit+=num;
            }
            else doubledigit+=num;
        }
        if(singledigit==doubledigit)return false;
        return true;
        
    }
};