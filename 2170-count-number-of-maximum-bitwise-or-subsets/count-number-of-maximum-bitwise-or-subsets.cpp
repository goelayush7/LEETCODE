class Solution {
public: 
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(auto it : nums){
            maxor = maxor | it;
        }
        int n = nums.size();
        int total = pow(2,n);
        int i =0;
        int count =0;
        while(i<total){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i & 1<<j){
                    temp.push_back(nums[j]);
                }
            }
            int ors = 0;
            for(auto it : temp){
                ors = ors | it;
            }
            if(ors==maxor)count++;
            i++;
        }
        return count;
    }
};