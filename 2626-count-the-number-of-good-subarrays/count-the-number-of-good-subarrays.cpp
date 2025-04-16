class Solution {
public:

    long long countGood(vector<int>& nums, int k) {
        int i  =0;
        int n = nums.size();
        unordered_map<int,long long>maps;
        int count = 0;
        long long ans = 0;
        for(int j = 0;j<n;j++){
            int num = nums[j];
            int freq = maps[num];
            count-=(freq*(freq-1))/2;
            maps[num]++;
            freq = maps[num];
            count+=(freq*(freq-1))/2;
            while(count>=k){
                ans += n-j;
                int curfreq = maps[nums[i]];
                int curadd = (curfreq*(curfreq-1))/2;
                maps[nums[i]]--;
                int newfreq = maps[nums[i]];
                int newadd = (newfreq*(newfreq-1))/2;
                count-= curadd-newadd;
                i++;
            }
        }
        return ans;
    }
};