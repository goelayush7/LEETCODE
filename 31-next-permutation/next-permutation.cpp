class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        bool flag = false;
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag = true;
                index = i;
                break;
            }
        }
        if(!flag){
            reverse(nums.begin(),nums.end());}
        else{
            for(int i = n-1;i>index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            sort(nums.begin()+index+1,nums.end());
        }
    }
};