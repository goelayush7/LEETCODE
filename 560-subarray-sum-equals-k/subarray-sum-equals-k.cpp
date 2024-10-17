class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;
        int sum =0;
        unordered_map<int,int>maps;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)count++;
            int target = sum-k;
            if(maps.find(target)!=maps.end()){
                count+=maps[target];
            }
            maps[sum]++;
        }
        return count;
    }
};