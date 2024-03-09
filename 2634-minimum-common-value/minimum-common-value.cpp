class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>maps;
        int n  = nums1.size();
        for(int i =0;i<n;i++){
            maps[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(maps.find(nums2[i]) != maps.end()) {
                return nums2[i];
            }
        }
        return -1;
    }
};