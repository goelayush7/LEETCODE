class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>maps;
        int n = nums.size();
        for(int i =0;i<n;i++){
            maps[nums[i]]++;
        }
        int maxi = INT_MIN;
        for(auto p: maps){
            maxi = max(p.second,maxi);
        }
        int count=0;
        for(auto p : maps){
            if(p.second==maxi){
                count +=p.second;
            }
        }
        return count;
    }
};