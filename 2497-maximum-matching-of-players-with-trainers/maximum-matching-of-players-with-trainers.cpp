class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n = players.size();
        int m = trainers.size();
        int count  =0;
        int j = 0;
        int i = 0;
        while(i<n){
            int num = players[i];
            while(j<m){
                if(num<=trainers[j]){
                    count++;
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
        return count;
    }
};