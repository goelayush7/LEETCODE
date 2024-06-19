class Solution {
public:
    bool helper(int mid, vector<int>& bloomDay, int m, int k) {
        int cons = 0;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cons++;
                if (cons == k) {
                    count++;
                    cons = 0;
                }
            } else {
                cons = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      int n = bloomDay.size();
        if ((long long)m * k > n) return -1;


        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int mini = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (helper(mid, bloomDay, m, k)) {
                mini = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mini;
    }
};
