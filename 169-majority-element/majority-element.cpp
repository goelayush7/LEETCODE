class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int n =nums.size();
        int ele = 1;
        for(int i =0;i<n;i++){
            if(count==0){
                ele = nums[i];
                count=1;
            }
            else if(ele != nums[i]){
                count--;
            }
            else count++;
        }
        count =0;
        for(int i =0;i<n;i++){
            if(nums[i]==ele)count++;
        }
        if(count>n/2)return ele;
        return -1;
    }
};