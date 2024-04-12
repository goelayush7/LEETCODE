class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int lsf[100000];
         int rsf[100000];

        lsf[n-1] = height[n-1];
        for(int i =n-2; i>=0 ; i--){
            lsf[i] = max(lsf[i+1],height[i]);
        }
        rsf[0]=height[0];
        for(int i=1;i<=n-1;i++){
            rsf[i] = max(rsf[i-1],height[i]);
        }
        for(int i =0;i<n;i++){
            ans+=min(rsf[i],lsf[i])-height[i];
        }
        return ans;
    }
};