class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if (hand.size() % gs != 0)
            return false;

        map<int, int> freq; // Use ordered map to maintain sorted keys
        for (int num : hand) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first; // Smallest number in hand
            for (int i = 0; i < gs; i++) {
                if (freq[start + i] == 0) 
                    return false; // If we can't form a group
                
                freq[start + i]--; // Use one instance of start + i
                
                if (freq[start + i] == 0) 
                    freq.erase(start + i); // Remove when count reaches 0
            }
        }
        return true;
    }
};
