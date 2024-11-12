class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        
        vector<int> ans(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int start = 0;
            int end = items.size() - 1;
            int maxi = 0;

            while (start <= end) {
                int mid = start + (end - start) / 2;
                
                if (items[mid][0] <= queries[i]) {
                    maxi = items[mid][1];  // Update maximum beauty
                    start = mid + 1;      // Look for a higher price within the query range
                } else {
                    end = mid - 1;        // Narrow down the search to lower prices
                }
            }
            ans[i] = maxi;
        }
        return ans;
    }
};
