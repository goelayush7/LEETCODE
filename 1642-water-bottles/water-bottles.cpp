
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int rem = 0;
        while (numBottles >= numExchange) {
            rem = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans += numBottles;
            numBottles += rem;
        }
        return ans;
    }
};
