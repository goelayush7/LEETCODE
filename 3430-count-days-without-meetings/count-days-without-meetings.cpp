class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>vect;
        for(auto it : meetings){
            if(vect.empty() || vect.back()[1]<it[0]){
                vect.push_back(it);
            }
            else{
                vect.back()[1] = max(vect.back()[1],it[1]);
            }
        }
        sort(vect.begin(),vect.end());
        int total = 0;
        for(auto it : vect){

            total+=it[1]-it[0]+1;
        }
        return days-total;
    }
};