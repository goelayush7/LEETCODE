class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long count=0;
        for(int i =0;i<n;i++){
            int num = nums[i];
            int start = i+1;
            int end = n-1;
            int largest = -1;
            while(start<=end){
                int mid = start + (end - start) / 2;
                if(nums[mid]+num<=upper){
                    largest = mid;
                    start = mid+1;
                }
                else end = mid-1;
            }
            start = i+1;
            end = n-1;
            int smallest = n;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(nums[mid]+num>=lower){
                    smallest = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
           if (smallest <= largest && smallest < n && largest >= 0) {
                count += (largest - smallest + 1);
            }
        }
        return count;
    }
};