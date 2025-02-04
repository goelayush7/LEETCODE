class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }
        vector<int>temp(nums2.size(),0);
        stack<int>st;
        int n = nums2.size();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = -1;
            }
            else temp[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i =0;i<nums1.size();i++){
            int val = nums1[i];
            int index = mp[val];
            ans.push_back(temp[index]);
        }
        return ans;
    }
};