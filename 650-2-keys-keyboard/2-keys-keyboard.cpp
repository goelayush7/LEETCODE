class Solution {
public:
    int steps(int n,int cur,int clipboard){
        if(cur==n){
            return 0;
        }
        if (cur > n) {
            return INT_MAX/2;
        }
        int min_steps = 2+steps(n,2*cur,cur);
        int steps1 = 1+steps(n,cur+clipboard,clipboard);
        return min(steps1,min_steps);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+steps(n,1,1);
    }
};