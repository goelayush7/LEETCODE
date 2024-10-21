class Solution {
public:
    void helper(string s, unordered_set<string>set,int i,int& maxcount,int curcount){
        if(i>=s.size()){
            maxcount = max(maxcount,curcount);
        }
        for(int j = i ;j<s.size();j++){
            string sub = s.substr(i,j-i+1);
            if(set.find(sub)==set.end()){
                set.insert(sub);
                helper(s,set,j+1,maxcount,curcount+1);
                set.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>set;
        int i =0;
        int j =0;
        int maxcount =0;
        int curcount =0;
        helper(s,set,i,maxcount,curcount);
        return maxcount;
    }
};