class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxzeroes = 0;
        int cur = 0;
        // checking for first index;

        if (seats[0] == 0) {
            int i = 0;
            while (seats[i] == 0) {
                i++;
                maxzeroes++;
            }
        }

        int i = seats.size() - 1;
        while (i >= 0 && seats[i] == 0) {
            cur++;
            i--;
        }
        maxzeroes = max(maxzeroes, cur);
        cout<<maxzeroes;
        int newmax = 0;
        cur = 0;
        for (auto it : seats) {
            if (it == 0)
                cur++;
            else
                cur = 0;
            newmax = max(newmax, cur);
        }
        
        if (newmax % 2 == 0) {
            if(maxzeroes>newmax/2)return maxzeroes;
            return newmax / 2;
        }
        if(maxzeroes>(newmax/2)+1)return maxzeroes;
        return (newmax / 2) + 1;
    }
};