class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0 and nums1==nums2)return 0;
        if(k==0)return -1;
        vector<int>temp;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            temp.push_back(nums2[i]-nums1[i]);
        }
        long long sum = 0;
        long long maxi = 0;
        for(auto it : temp){
            if(it%k!=0)return -1;
            if(it>0)maxi+=it;
            sum+=it;
        }
        if(sum==0)return maxi/k;
        return -1;
    }
};