class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2,int diff){
        int count =0; int j =0;
        for(int i =0;i<nums1.size() && j<nums2.size();i++){
            if(nums1[i]+diff!=nums2[j])count++;
            else j++;
        }
        return (count<=2);
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int mini = INT_MAX;
        for(int i =0;i<min(3,(int)nums1.size());i++){
            int x = nums2[0]-nums1[i];
            if(check(nums1,nums2,x)){
                mini = min(x,mini);
            }
        }
        return mini;
    }
};