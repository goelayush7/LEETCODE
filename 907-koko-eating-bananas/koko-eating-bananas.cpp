class Solution {
public:
    bool canbedone(vector<int>piles,int h,int k){
        int curcount =0;
        for(auto it : piles){
            curcount += (it + k - 1) / k;
            if(curcount>h)return false;
        }
        return curcount<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        for(auto it : piles){
            end = max(end,it);
        }
        int ans =end;
        while(start<=end){
            int mid = start + (end-start)/2;
            bool val = canbedone(piles,h,mid);
            if(val){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};