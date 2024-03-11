#include <string>

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>maps1;
        for (char c : s) {
            maps1[c]++;
        }

        int i =0;
        string ans="";
        while(i<order.size()){
            if(maps1[order[i]]!=0){
                ans+=order[i];
                maps1[order[i]]--;
            }
            else i++;
        }
        for(auto p : maps1){
            while(p.second!=0){
                ans+=p.first;
                p.second--;
            }
        }
        return ans;
    }
};
