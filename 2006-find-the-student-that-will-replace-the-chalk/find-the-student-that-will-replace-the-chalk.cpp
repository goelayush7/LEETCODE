class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        
        // Calculate total chalk used in one complete round
        for (int c : chalk) {
            totalChalk += c;
        }
        
        // Reduce k by the total chalk used in one round
        k %= totalChalk;
        
        // Find the student who will use the remaining chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This line should never be reached because the problem guarantees a solution
        return -1;
    }
};
