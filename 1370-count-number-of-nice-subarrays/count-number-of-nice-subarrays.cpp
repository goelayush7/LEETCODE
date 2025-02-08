class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        int count =0;
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==1){
                count++;
            }
            if(count==k)ans++;
            if(maps.find(count-k)!=maps.end()){
                ans+=maps[count-k];
            }
            maps[count]++;
        }
        return ans;
    }
};