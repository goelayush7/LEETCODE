class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int cpy = x;
        while(cpy!=0){
            sum+=cpy%10;
            cpy = cpy/10;
        }
        if(x%sum==0) return sum;
        return -1;
    }
};