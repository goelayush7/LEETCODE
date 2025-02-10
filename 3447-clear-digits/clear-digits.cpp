class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                s.erase(i, 1);
                if (i > 0) {
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] >= 'a' && s[j] <= 'z') {
                            s.erase(j, 1);
                            i--;  
                            break;
                        }
                    }
                }
            } else {
                i++;
            }
        }
        return s;
    }
};
