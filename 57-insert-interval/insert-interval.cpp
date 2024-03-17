class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size(); // Size of the array 
        vector<vector<int>>ans;

        // sort the given intervals
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++)
        {
            //if the current interval does not exist in the last interval
            if(ans.empty() || intervals[i][0]> ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                //if the current interval lies in the last interval
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        return ans;
    }
};