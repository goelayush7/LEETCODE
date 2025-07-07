class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>temp(n+1,0);
        for(auto it : queries){
            int start = it[0];int end = it[1];
            temp[start]-=1;
            temp[end+1]+=1;
        }
        vector<int>prefix;
        int sum = 0;
        for(auto it : temp){
            sum+=it;
            prefix.push_back(sum);
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>abs(prefix[i]))return false;
        }
        return true;
    }
};