class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> maps;
        int ans = 0;
        int countzero =0;
        for (auto it : answers) {
            if(it==0){
                countzero++;
                continue;
            }
            maps[it]++;
        }
        for (auto it : maps) {
            double value = it.first+1;
            double count = it.second;
            if(count>value){
                ans+=ceil(count/(value))*value;
            }
            else ans+=value;   
        }
        cout<<countzero;
        return ans+=countzero;
    }
};