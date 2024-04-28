class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int maxi1 =  INT_MIN;
        int maxi2 = INT_MIN;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]>maxi1) maxi1 = nums1[i];
            if(nums2[i]>maxi2) maxi2 = nums2[i];
        }
        return maxi2-maxi1;
        
    }
};