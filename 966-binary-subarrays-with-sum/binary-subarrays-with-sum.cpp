class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count =0;
        int sum = 0;
        unordered_map<int,int>map;
        for(int i =0; i < nums.size() ; i++){
            sum+=nums[i];
            if(sum==goal)count++;
            if(map.find(sum-goal)!=map.end()){
                count+=map[sum-goal];
            }
            if(map.find(sum)==map.end()){
                map[sum]=1;
            }
            else{
                map[sum]++;
            }
        }
        return count;
    }
};