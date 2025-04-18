class Solution {
public:
    int mod = 1000000007;

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxih = 0;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxih = max(maxih, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        int maxiv = 0;
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxiv = max(maxiv, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return (1LL * maxih * maxiv) % mod;  // Use 1LL to avoid overflow
    }
};
