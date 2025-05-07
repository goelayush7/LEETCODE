class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int>res = {1};
        if(n==1)return res;
        while(res.size()<n){
            vector<int>temp;
            for(auto it : res){
                if(2*it<=n){
                    temp.push_back(2*it);
                }
            }
            for(auto it : res){
                if(2*it-1<=n){
                    temp.push_back(2*it-1);
                }
            }
            res = temp;
        }
        return res;
    }
};