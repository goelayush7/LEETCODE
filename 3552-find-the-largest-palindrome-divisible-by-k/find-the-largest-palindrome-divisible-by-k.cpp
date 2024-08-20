class Solution {
public:
    int f(int i, int prevMod, int &halfn, int &n, int &k, vector<int> &powers,
            vector<int>& res, vector<vector<int>>& dp){
        // Base case : required no of digits chosen
        if(i == halfn)
            return prevMod == 0;        // divisble by k

        // already calculated
        if(dp[i][prevMod] != -1)
            return dp[i][prevMod];

        // int oi = n - 1 - i;     // same digit to satisfy palindrome property
        for(int d = 9; d >= 0; d--) { // try each digit starting from largest
            // calcualte new mod after adding current digit at i and n-1-i
            // n is odd and we are at middle element -> i and n-1-i will be same -> count once
            int newMod = prevMod;
            if ((n & 1) && (i == halfn - 1)) {
                newMod += (d * powers[i]) % k;
            } else {    // i and n-1-i are different -> add contribution of both
                newMod += (d * powers[i]) % k;
                newMod += ((d * powers[n - 1 - i])) % k;
            }
            newMod %= k;

            int flag = f(i + 1, newMod, halfn, n, k, powers, res, dp);
            if (flag) {
                res[i] = d;     // largest digit found for this index
                break;
            }
        }

        if(res[i] == -1)
            return dp[i][prevMod] = 0;     
         return dp[i][prevMod] = 1;   
    }

    string largestPalindrome(int n, int k) {
        int halfn = (n+1)/2;
        // preprocess (10^i) % k 
        vector<int> powers(n, 0);
        powers[0] = 1 % k;
        for (int i = 1; i < n; i++)
            powers[i] = (powers[i-1] * 10) % k;

        // Recursively calculate result using digit dp
        vector<int> res(n, -1); // to store best value at each place
        vector<vector<int>> dp(halfn, vector<int>(10, -1));
        int prevMod = 0;
        // index, prevMod, halfn, n, k , powers, res, dp
        f(0, prevMod, halfn, n, k, powers, res, dp);

        // update ans using res
        string ans(n, '0');
        for(int i = 0; i < halfn; i++){
            ans[i] = '0' + res[i];
            ans[n-i-1] = ans[i];
        }
        return ans;
    }
};