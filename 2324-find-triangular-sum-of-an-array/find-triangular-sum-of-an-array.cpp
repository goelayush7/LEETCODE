class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n--){
            vector<int>temp;
            for(int i = 0; i <nums.size()-1;i++){
                int sum = nums[i]+nums[i+1];
                temp.push_back(sum%10);
            }
            nums = temp;
        }
        return nums[0];
    }
};