
class Solution {
public:
    bool f(int a, int b) {
        string val = to_string(b);
        int n = val.size();
        if(a==b)return true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(val[i], val[j]);  // Swap digits
                
                // Check if it matches 'a'
                if (stoi(val) == a) {
                    return true;
                }
                
                swap(val[i], val[j]);  // Swap back to original state
            }
        }
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num1 = nums[i];
                int num2 = nums[j];
                
                if (f(num1, num2) || f(num2, num1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
