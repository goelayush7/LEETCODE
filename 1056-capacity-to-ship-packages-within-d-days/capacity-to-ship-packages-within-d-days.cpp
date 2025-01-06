class Solution {
public:
    bool trial(vector<int>weights,int days,int mid){
        int day = 1;
        int sum =0;
        for(int i =0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                day++;
                sum = weights[i];
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(start<=end){
            int mid = start + (end-start)/2;
            bool flag = trial(weights,days,mid);
            if(flag){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};