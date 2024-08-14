class Solution {
public:
    int countres(vector<int>&nums,int d){
        int i =0;
        int j = 1;
        int res = 0;
        int  n = nums.size();
        while(j<n){
            while(nums[j]-nums[i]>d){
                i++;
            }
            res+=j-i;
            j++;
        }
        return res;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // int n =nums.size();
        // int maxi = *max_element(nums.begin(),nums.end());
        // vector<int>vect(maxi+1,0);
        // for(int i =0;i<nums.size();i++){
        //     for(int j = i+1 ;j<n;j++){
        //         int d = abs(nums[j]-nums[i]);
        //         vect[d]++;
        //     }
        // }
        // int ans;
        // for(int i =0;i<vect.size();i++){
        //     k-=vect[i];
        //     if(k<=0){
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0;
        int r =nums[n-1]-nums[0];
        int result =0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int count = countres(nums,mid);
            if(count<k){
                l =mid+1;
            }
            else{
                result = mid;
                r = mid-1;
            }
        }
        return result;
    }
};