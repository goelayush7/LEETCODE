class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>>pq;
        int n = aliceValues.size();
        for(int i = 0;i<n;i++){
            int value = aliceValues[i]+bobValues[i] ; 
            pq.push({value,i});
        }
        int alicep = 0;
        int bobp = 0;
        bool alice = true;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int index = it.second;
            if(alice){
                alicep += aliceValues[index];
                alice = !alice;
            }
            else{
                bobp += bobValues[index];
                alice = !alice;
            }
        }
        if(alicep==bobp)return 0;
        if(alicep>bobp)return 1;
        return -1;
    }
};