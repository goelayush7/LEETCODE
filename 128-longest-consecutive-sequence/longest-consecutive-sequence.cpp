class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int longest =0;
        for(auto num:nums){
            s.insert(num);
        }
        for(auto it :s){
            if(s.find(it-1)==s.end()){
                int cnt =1;
                int x = it;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x = x+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};