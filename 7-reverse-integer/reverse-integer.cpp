class Solution {
public:
    int reverse(int x) {
        long ans =0;
        bool flag = true;
        if(x<0) flag=false;
        x = abs(x);
        while(x!=0){
            int digit = x%10;
            ans = ans*10 +digit;
            x = x/10;
        }
        if(ans>INT_MAX || ans<INT_MIN)return 0;
        if(flag==true)return ans;
        return -ans;
    }
};