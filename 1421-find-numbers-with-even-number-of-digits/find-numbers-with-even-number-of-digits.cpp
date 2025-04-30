class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto it : nums){
            int num = it;
            int temp = 0;
            while(num>0){
                temp++;
                num = num/10;
            }
            if(temp%2==0)count++;
        }
        return count;
    }
};