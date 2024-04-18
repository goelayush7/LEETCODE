class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i =0;i<n;i++){
            int j =i+1;
            int k = n-1;
            while(j<k){
                long long sum = 0;
                sum+=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else k--;
            }
        }
        for(auto i : s){
            ans.push_back(i);
        }
        return ans;
        
    }
};