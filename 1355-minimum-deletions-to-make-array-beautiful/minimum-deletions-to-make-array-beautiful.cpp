class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count  =0;
        for(int i = 0;i<nums.size()-1;i++){
            if((i-count)%2==0 && nums[i]==nums[i+1]){
                    count++;
            }
        }
        if((nums.size()-count)%2==1){
            count++;
        }
        return count;
    }
};