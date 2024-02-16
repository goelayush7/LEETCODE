class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum =0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
                set<vector<int>> s;
        vector<vector<int>>output;
        for(int i =0;i<n;i++){
           int j = i+1;
           int k = n-1;
           while(k>j){
               if(nums[i] + nums[j] + nums[k] == 0){
                   s.insert({nums[i],nums[j],nums[k]});
                   j++;
                   k--;
               }
               else if(nums[i] + nums[j] + nums[k] > 0){
                   k--;
               }
               else{
                   j++;
               }
           }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};