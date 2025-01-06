class Solution {
public:
    bool trial(vector<int>&bloomday,int m,int k ,int mid){
        int flowers = 0;
        int boq = 0;
        for(int i =0;i<bloomday.size();i++){
            if(bloomday[i]<=mid){
                flowers++;
                if(flowers==k){
                    boq++;
                    flowers=0;
                }
            }
            else flowers=0;
        }
        return boq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start =1;
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            bool flag = trial(bloomDay,m,k,mid);
            if(flag){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};