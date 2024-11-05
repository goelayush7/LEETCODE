class Solution {
    #define mod 1000000007
public:
    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long ans = power(x, n / 2);
        ans = (ans * ans) % mod;
        if (n % 2 != 0) {
            ans = (ans * x) % mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long num = power(4, odd);
        long long num2 = power(5, even);
        int ans = (num * num2) % mod;
        return ans;
    }
};
