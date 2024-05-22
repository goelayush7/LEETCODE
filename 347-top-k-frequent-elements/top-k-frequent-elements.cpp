class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        int n = nums.size();
        for(int i =0;i<n;i++){
            maps[nums[i]]++;
        }
        vector<vector<int>>out;
        for(auto it:maps){
            out.push_back({it.second,it.first});
        }
        sort(out.begin(),out.end());
        reverse(out.begin(),out.end());
        vector<int>ans;
        int i=0;
        while(k){
            ans.push_back(out[i][1]);
            i++;
            k--;
        }
        return ans;
        
    }
};