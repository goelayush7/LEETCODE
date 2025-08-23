class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int sum = 0;
        int reqsum = 0;
        int count = 0;
        for(int i = 0;i<flips.size();i++){
            reqsum+=i+1;
            sum+=flips[i];
            if(sum==reqsum)count++;
        }
        return count;
    }
};