class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>out;
        int x = nums[0];
        vector<int>cpy;
        int val = pow(2,maximumBit)-1;
        cpy.push_back(x);
        for(int i =1;i<nums.size();i++){
            x = x^nums[i];
            cpy.push_back(x);
        }
        reverse(cpy.begin(),cpy.end());
        for(auto it : cpy){
            out.push_back(it^val);
        }
        return out;
    }
};