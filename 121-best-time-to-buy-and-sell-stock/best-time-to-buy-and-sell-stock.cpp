class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini =INT_MAX;
        int maxi = INT_MIN;
        for(auto it : prices){
            mini = min(it,mini);
            maxi = max(maxi,it-mini);
        }
        return maxi;
    }
};