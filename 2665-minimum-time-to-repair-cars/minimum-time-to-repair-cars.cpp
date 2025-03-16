class Solution {
public:
    bool helper(vector<int>& ranks, int cars, long long mid) {
        int total = 0;
        for (auto it : ranks) {
        int countcars = 1;
            total+=(long long)sqrt(mid/it) ;
            if(total>=cars)return true;
            
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1;
        long long end = 1LL**min_element(ranks.begin(), ranks.end()) * cars*cars;
        long long ans = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (helper(ranks, cars, mid)) {
                ans = mid;
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans;
    }
};