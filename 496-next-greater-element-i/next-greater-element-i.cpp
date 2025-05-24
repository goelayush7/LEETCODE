class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        unordered_map<int, int> maps;
        vector<int> temp(n,-1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(!st.empty()){
                temp[i] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i = 0;i<n;i++){
            maps[nums2[i]] = temp[i];
        }
        vector<int>ans;
        for(auto it : nums1){
            ans.push_back(maps[it]);
        }
        return ans;
    }
};