class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>newnums;
        for(int i =0;i<nums.size()*2;i++){
            newnums.push_back(nums[i%nums.size()]);
        }
        stack<int>st;
        int n = newnums.size()-1;
        vector<int>temp(newnums.size());
        for(int i = n;i>=0;i--){
            while(!st.empty() && st.top()<=newnums[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = -1;
            }
            else temp[i] = st.top();
            st.push(newnums[i]);
        }
        for(auto it : temp){
            cout<<it<<endl;
        }
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};