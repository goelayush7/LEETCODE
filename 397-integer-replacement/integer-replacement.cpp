class Solution {
public:
    int helper(long long n){
        if(n == 1){
            return 0;
        }
        int half = INT_MAX;
        if(n % 2 == 0){
            half = 1 + helper(n / 2);
        }
        int minus = INT_MAX;
        int plus = INT_MAX;
        if(n % 2 != 0){
            minus = 1 + helper(n - 1);
            plus = 1 + helper(n + 1);
        }
        return min({half, minus, plus});
    }

    int integerReplacement(int n) {
        return helper((long long)n);
    }
};
