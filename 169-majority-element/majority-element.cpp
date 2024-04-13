class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele =1;
        int n = nums.size();
        int count=0;
        int i=0;
        while(i<n){
            if(count==0){
                ele=nums[i];
                count=1;
            }
            else if(ele==nums[i]){
             
                count++;
            }
            else{
                count--;
            }
            i++;
        }
        //ele can be our element
        count =0;
        for(int i =0;i<n;i++){
            if(ele==nums[i]){
                count++;
            }
        }
        if(count>n/2)return ele;
        return -1;
        
    }
};