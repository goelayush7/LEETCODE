class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> maps;

        for (int i = 1; i <= n; i++) {
            int num = i, sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            maps[sum]++;
        }

        int maxi = 0;
        for (auto& it : maps) {
            maxi = max(maxi, it.second);
        }

        int count = 0;
        for (auto& it : maps) {
            if (it.second == maxi) count++;
        }

        return count;
    }
};
