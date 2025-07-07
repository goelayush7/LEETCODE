class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int i =0;
        int j = 0;
        int count =0;
        while(j<k){
            sum+=arr[j];
            j++;
        }
        if((sum/k)>=threshold)count++;
        int n = arr.size();
        while(j<n){
            sum-=arr[i];
            i++;
            sum+=arr[j];
            if((sum/k)>=threshold)count++;
            j++;
        }
        return count;

    }
};