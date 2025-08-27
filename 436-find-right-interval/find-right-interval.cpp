class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>,int>maps;
        int n = intervals.size();
        for(int i =0;i<n;i++){
            maps[intervals[i]] = i;
        }
        vector<int>ans(n,-1);
        sort(intervals.begin(),intervals.end());
        for(auto it : intervals){
            int start = 0;
            int end = intervals.size()-1;
            int tofind = it[1];
            int ind = -1;
            while(start<=end){
                int mid = start +(end-start)/2;
                if(intervals[mid][0]>=tofind){
                    ind = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            ans[maps[it]] = (ind == -1 ? -1 : maps[intervals[ind]]);

        }
        return ans;
    }
};