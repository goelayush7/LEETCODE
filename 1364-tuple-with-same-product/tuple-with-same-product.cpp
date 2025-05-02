class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>maps;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                int value = nums[i]*nums[j];
                maps[value]++;
            }
        }
        int ans = 0;
        for(auto it : maps){
            if(it.second>=1){
                int val = it.second;
                int valu = (val*(val-1))/2;
                ans+=valu*8;
            }
        }
        return ans;
    }
};