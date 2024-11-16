class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        deque<int>deq;
        for(int i=0;i<n;++i){
            if(!deq.empty() and deq.front()<=i-k){
                deq.pop_front();
            }
            while(!deq.empty() and nums[deq.back()] != nums[i]-1){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i>=k-1){
                if(deq.size()==k){
                    res.push_back(nums[deq.back()]);
                } else {
                    res.push_back(-1);
                }
            }


        }
        return res;
        
    }
};