class Solution {
public:
    int checksetbits(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) { // Assuming 32-bit integer
            if (n & (1 << i)) {
                count++;
            }
        }
        return count;
    }
    bool checksort(vector<int>nums){
        for(int i =1;i<nums.size();i++){
            if(nums[i-1]>nums[i])return false;
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            for(int j =0;j<n-i-1;j++){
                if(nums[j]>nums[j+1] && checksetbits(nums[j])==checksetbits(nums[j+1])){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        if(checksort(nums))return true;
        return false;
    }
};