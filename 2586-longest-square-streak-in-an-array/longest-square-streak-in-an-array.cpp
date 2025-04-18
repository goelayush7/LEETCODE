class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>maps;
        int maxi = *max_element(nums.begin(),nums.end());

        for(auto it : nums){
            maps[it]++;
        }
        int maxc = 1;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            int curc = 1;
            while(1LL*num*num<=maxi){
                if(maps.find(num*num)!=maps.end()){
                    curc++;
                    num = num*num;
                }
                else break;
            }
            maxc = max(maxc,curc);
        }
        if(maxc<2)return -1;
        return maxc;
    }
};