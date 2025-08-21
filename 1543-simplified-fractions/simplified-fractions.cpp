class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int i = 2; i <= n;i++){
            for(int j = 1;j<i;j++){
                float temp = j/i;
                if(temp<n && gcd(i,j)==1){
                    ans.push_back((to_string(j) + "/" + to_string(i)));
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};