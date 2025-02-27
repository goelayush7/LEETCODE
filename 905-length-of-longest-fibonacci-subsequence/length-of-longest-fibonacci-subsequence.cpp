class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>maps(arr.begin(),arr.end());
        int n = arr.size();
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int sum = arr[i];

                sum+=arr[j];
                int count =2;
                int prev = arr[j];
                while(maps.find(sum)!=maps.end()){
                    int cpy = sum;
                    sum +=prev;
                    prev= cpy;count++;
                    ans = max(ans,count);
                }
            }
        }
        return ans;

    }
};