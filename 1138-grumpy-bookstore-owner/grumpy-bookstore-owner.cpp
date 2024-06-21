class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = grumpy.size();
        int wpo = 0;
        for(int i =0;i<n;i++){
            if(grumpy[i]==0){
                wpo += customers[i];
            }
        }
        int i =0;
        int j =0;
        int maxi =0;
        while(j<k){
            if(grumpy[j]==1){
                wpo+=customers[j];
            }
            j++;
            maxi= max(maxi,wpo);
        }
        while(i<n && j<n){
            if(grumpy[i]==1){
                wpo-=customers[i];
            }
            i++;
            if(grumpy[j]==1){
                wpo+=customers[j];
            }
            maxi = max(maxi,wpo);
            j++;
        }
        return maxi;
    }
};