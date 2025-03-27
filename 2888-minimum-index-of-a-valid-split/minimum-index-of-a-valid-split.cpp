class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>maps1;
        unordered_map<int,int>maps2;
        for(int i = 0;i<nums.size();i++){
            maps1[nums[i]]++;
        }
        int ans = -1;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            maps2[nums[i]]++;
            if(maps2[nums[i]]>(i+1)/2){
                if((n-i-1)==0) break;
                if((maps1[nums[i]]-maps2[nums[i]])>(n-i-1)/2){
                    return i;
                }
            }
        }
        return ans;
    }
};