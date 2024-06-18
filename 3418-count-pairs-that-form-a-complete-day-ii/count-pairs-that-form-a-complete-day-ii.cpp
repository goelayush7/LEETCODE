class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>remainder_value;
        long long count =0;
        for (auto hour:hours){
            int remainder = hour%24;
            if(remainder==0)count+=remainder_value[0];
            else{
                count+=remainder_value[24 - remainder];
            }
            remainder_value[remainder]++;
        }
        return count;
    }
};