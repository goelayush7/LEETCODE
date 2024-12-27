class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        int sum =0;
        int count =0;
        for(auto it : nums){
            sum+=it;
            if(sum==k)count++;
            if (maps.find(sum-k)!=maps.end()){
                count+=maps[sum-k];
            }
            maps[sum]++;
        }
        return count ;
    }
};