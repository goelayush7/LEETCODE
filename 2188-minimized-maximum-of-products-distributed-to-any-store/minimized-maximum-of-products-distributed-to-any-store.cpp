class Solution {
public:
    bool func(int n,vector<int>&q,int mid){
        int maxi = 0;
        for(auto it : q){
            int curcount  = (it+mid-1)/mid;
            maxi +=curcount;
            if(maxi>n)return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int start =1;
        int end = *max_element(q.begin(),q.end());
        int ans =0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(func(n,q,mid)){
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