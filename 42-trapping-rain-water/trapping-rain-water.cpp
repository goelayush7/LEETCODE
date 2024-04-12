class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lsf[100000];
        lsf[0] = height[0];
        for(int i =1 ; i< n ; i++){
            lsf[i] = max(lsf[i-1],height[i]);
        }
        int rsf[100000];
        rsf[n-1] = height[n-1];
        for(int i = n-2; i>=0 ; i--){
            rsf[i] = max(rsf[i+1],height[i]);
        }
        int totalwater =0;
        for(int i =0;i<n ; i++){
            totalwater += min(lsf[i],rsf[i])-height[i];
        }
        return totalwater;
    }
};