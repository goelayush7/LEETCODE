class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>maps;
        int i = 0;
        int longest = INT_MAX ;
        for(int j = 0;j<cards.size();j++){
            maps[cards[j]]++;
            while(maps[cards[j]]==2 && i<cards.size()){
                longest = min(longest,j-i+1);

                maps[cards[i]]--;
                i++;
            }
        }    
        return longest==INT_MAX ? -1 : longest;    
    }
};