class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>maps;
        for(auto& it : matrix){
            string temp="";
            for(int i =0;i<it.size();i++){
                if(it[0]==it[i])temp+='T';
                else temp+='F';
            }
            maps[temp]++;
        }
        int maxi = 0;
        for(auto it : maps){
            maxi = max(maxi,it.second);
        }
        return maxi;
    }
};