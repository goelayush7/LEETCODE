class FindSumPairs {
public:
    unordered_map<int, int> maps; // frequency map for nums2
    vector<int> agg;
    vector<int> nums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        agg = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            maps[num]++;
        }
    }
    
    void add(int index, int val) {
        maps[nums2[index]]--;       // decrement old value count
        nums2[index] += val;        // update value
        maps[nums2[index]]++;       // increment new value count
    }

    int count(int tot) {
        int count = 0;
        for (int num : agg) {
            int target = tot - num;
            if (maps.find(target) != maps.end()) {
                count += maps[target];  // add frequency count of complement
            }
        }
        return count;
    }
};
