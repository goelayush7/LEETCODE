class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(int i = 0 ; i <left.size();i++){
            ans = max(ans,abs(0-left[i]));
        }
        for(auto it :right){
            ans = max(ans,abs(n-it));
        }
        return ans;
    }
};