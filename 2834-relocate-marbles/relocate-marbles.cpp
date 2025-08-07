class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mF, vector<int>& mT) {
        unordered_set<int>st(nums.begin(),nums.end());
        int n = mF.size();
        for(int i = 0;i<n;i++){
            st.erase(mF[i]);
            st.insert(mT[i]);
        }
        vector<int>ans;
        for(auto it : st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};