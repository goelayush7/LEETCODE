class Solution {
public:
    bool trial(vector<int>&piles,int h,int mid){
        long long ans = 0;
        for(auto it : piles){
            ans += (it + mid - 1) / mid;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            bool flag = trial(piles,h,mid);
            if(flag==true){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
    return ans;

    }
};