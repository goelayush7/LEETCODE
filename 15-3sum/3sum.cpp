class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>out;
        set<vector<int>>st;
        for(int i =0;i<n;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int val = nums[i]+nums[j]+nums[k];
                if(val==0){
                    st.insert({nums[i],nums[j],nums[k]});
                }
                if(val>0){
                    k--;
                }
                else j++;
            }
        }
        for(auto it :st){
            out.push_back(it);
        }
        return out;
    }
};