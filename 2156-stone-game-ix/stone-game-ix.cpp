class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        unordered_map<int,int>count;
        for(auto it : stones)count[it%3]++;

        if(count[0]%2==0){
            if(count[1]==0 || count[2]==0)return false;
            return true;
        }
        else{
            if(abs(count[1]-count[2])>2)return true;
            return false;
        }
    }
};