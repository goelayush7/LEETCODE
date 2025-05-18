class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int>maps;
        int sum = 0;
        int count =0;
        int iter = 1;
        while(count<n){
            if(maps.find(k-iter)==maps.end()){
                count++;
                sum+=iter;
            }
            maps[iter]++;
            iter++; 
        }
        return sum;
    }
};