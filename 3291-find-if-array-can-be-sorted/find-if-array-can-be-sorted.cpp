class Solution {
public:
    int checksetbits(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                count++;
            }
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int prevmax = INT_MIN;
        int curmin = nums[0];
        int curmax =nums[0];
        int setBits = checksetbits(nums[0]);
        for(int i =1;i<nums.size();i++){
            if(checksetbits(nums[i])==setBits){
                curmax = max(curmax,nums[i]);
                curmin = min(curmin,nums[i]);
            }
            else{
                if(prevmax>curmin)return false;
                prevmax = curmax;
                setBits = checksetbits(nums[i]);
                curmin = nums[i];
                curmax = nums[i];
            }
        }
        return curmin>prevmax;
    }
};