class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>temp;
        long long prefixsum = 0;
        for(auto it : nums){
            prefixsum+=it;
            temp.push_back(prefixsum);
        }
        int ans = 0;
        for(int i =0;i<nums.size()-1;i++){
            long long val1 = temp[i];
            long long val2 = temp[nums.size()-1]-val1;
            if(val1>=val2)ans++;
        }
        return ans;
    }
};