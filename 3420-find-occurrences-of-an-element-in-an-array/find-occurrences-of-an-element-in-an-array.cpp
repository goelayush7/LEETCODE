class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>maps;
        int ith =1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==x){
                maps[ith] = i;
                ith++;
            }
        }
        vector<int>ans;
        for(int i =0;i<queries.size();i++){
            if(maps.find(queries[i])!=maps.end()){
                ans.push_back(maps[queries[i]]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};