class Solution {
public:
    double isans(double x,int n){
        if(n==0)return 1;
        double temp = pow(x,n/2);
        temp = temp*temp;
        if(n%2!=0){
            return x*temp;
        }
        else return temp;
    }
    double myPow(double x, int n) {
        if(n==INT_MAX)return (x==1) ? 1:(x==-1)?-1:0;
        if(n==INT_MIN)return (x==-1 || x==1) ? 1:0;
        double ans = isans(x,abs(n));
        if(n<0)ans = 1.0/ans;
        return ans;

        
    }
};