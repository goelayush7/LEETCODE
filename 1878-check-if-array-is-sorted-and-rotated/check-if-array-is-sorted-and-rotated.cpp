class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>copy = nums;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                temp.push_back(copy[(j+i)%n]);
            }
            if(temp==nums)return true;
        }
        return false;
    }
};