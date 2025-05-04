class Solution {
public:
    int mod = 1e9+7;
    int countPairs(vector<int>& del) {
        vector<int>temp;
        temp.push_back(1);
        unordered_map<int,int>maps;
        for(int i = 1;i<=21;i++){
            temp.push_back(pow(2,i));
        }
        int count=0;
        sort(del.begin(),del.end());
        for(auto it : del){
            int start = it;
            for(int i =0;i<temp.size();i++){
                int rem = temp[i]-start;
                if(rem>=0 && rem<=start){
                    if(maps.find(rem)!=maps.end()){
                        count+=maps[rem];
                        count = count%mod;
                    }
                }
                if(rem>start)break;
            }
            maps[it]++;
        }
        return count;
    }
};