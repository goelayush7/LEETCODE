class Solution {
public:
    bool helper(vector<int>&weights,int days,int mid){
        int count  = 1;
        int curw = 0;
        for(auto it : weights){
            if(curw+it<=mid){
                curw+=it;
            }
            else{
                curw = it;
                count++;
            }
            
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start  = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(helper(weights,days,mid)){
                ans = min(ans,mid);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};