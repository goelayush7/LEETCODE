class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> maps;
        int n = nums2.size();
        
        // Count pairs in nums2 where product equals square of nums1 element
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long product = (long long)nums2[i] * nums2[j];
                maps[product]++;
            }
        }
        
        int ans = 0;
        for (auto it : nums1) {
            long long square = (long long)it * it;
            if (maps.count(square)) {
                ans += maps[square];
            }
        }
        
        maps.clear();
        int m = nums1.size();
        
        // Count pairs in nums1 where product equals square of nums2 element
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                long long product = (long long)nums1[i] * nums1[j];
                maps[product]++;
            }
        }
        
        for (auto it : nums2) {
            long long square = (long long)it * it;
            if (maps.count(square)) {
                ans += maps[square];
            }
        }
        
        return ans;
    }
};
