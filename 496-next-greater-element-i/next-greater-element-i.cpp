class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>v1;
        map<int,int>map;
        int n = nums2.size();
        for(int i = n-1; i>=0 ; i--){
            while(!v1.empty() && v1.top()<=nums2[i]){
                    v1.pop();
            }
            if(v1.empty()){
                map[nums2[i]]=-1;
            }
            else{
                map[nums2[i]]=v1.top();
            }
            v1.push(nums2[i]);
        }
        vector<int>v(nums1.size(),-1);
        for(int i =0;i<nums1.size();i++){
            v[i] = map[nums1[i]];
        }
        return v;

    }
};