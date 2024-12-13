class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>>temp;
        for(int i =0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,bool>maps;
        long long ans = 0;
        for(auto it: temp){
            int num = it.first;
            int index = it.second;
            if(maps.find(index)==maps.end()){
                maps[index]=true;
                ans+=num;
                if(index>0)maps[index-1]=true;
                if(index+1<nums.size())maps[index+1]=true;
            }
        }
        return ans;
        
    }
};