class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>vect;
        for(auto it : arr){
            int dif = abs(it-x);
            vect.push_back({dif,it});
        }
        sort(vect.begin(),vect.end());
        vector<int>ans;
        int i = 0;
        while(k--){
            ans.push_back(vect[i].second);
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};