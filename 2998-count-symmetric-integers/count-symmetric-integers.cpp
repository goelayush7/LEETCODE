class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        
        for (int i = low; i <= high; i++) {
            int sum1 = 0;
            int sum2 = 0;
            int num = i;
            int count = 0; 
            
            while (num != 0) {
                count++;
                num = num / 10;
            }
            
            if (count % 2 != 0) {
                continue;
            }
            
            int s = 0;
            int j = i;
            while (s < count / 2) {
                sum1 += j % 10;
                j = j / 10;
                s++;
            }
            
            while (s < count) {
                sum2 += j % 10;
                j = j / 10;
                s++;
            }
            
            if (sum1 == sum2) {
                ans++;
            }
        }
        
        return ans;
    }
};
