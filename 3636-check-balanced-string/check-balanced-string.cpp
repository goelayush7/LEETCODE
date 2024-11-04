class Solution {
public:
    bool isBalanced(string nums) {
        int odd = 0;
        int even = 0;
        for(int i =0;i<nums.size();i++){
            if(i==0 || i%2==0)even+=nums[i]-'0';
            else odd+=nums[i]-'0';
        }
        return odd==even;
    }
};