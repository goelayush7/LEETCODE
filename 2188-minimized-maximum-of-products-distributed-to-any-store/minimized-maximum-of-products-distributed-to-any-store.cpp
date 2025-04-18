class Solution {
public:
    bool helper(int n,vector<int>&quantities,int maxi){
        int count  = 0;
        for(int i = 0;i<quantities.size();i++){
            count += (quantities[i] + maxi - 1) / maxi;
        }
        return count<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start =1;
        int end = *max_element(quantities.begin(),quantities.end());
        while(start<=end){
            int mid = start + (end-start)/2;
            if(helper(n,quantities,mid)){
                end = mid-1;
            }
            else start = mid+1;
        }
        return end+1;
    }
};