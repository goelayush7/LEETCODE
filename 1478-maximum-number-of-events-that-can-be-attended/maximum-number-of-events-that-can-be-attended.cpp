class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        // Step 1: Sort events by start day
        sort(events.begin(), events.end());

        // Step 2: Min-heap for end days
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        int i = 0;
        int count = 0;
        int n = events.size();

        int lastDay = 0;
        for (const auto& e : events) 
        {
            lastDay = max(lastDay, e[1]);
        }

        for (int day = 1; day <= lastDay; day++) 
        {
            while (i < n && events[i][0] == day) 
            {
                minHeap.push(events[i][1]);
                i++;
            }
            while (!minHeap.empty() && minHeap.top() < day) 
            {
                minHeap.pop();
            }

            if (!minHeap.empty()) 
            {
                minHeap.pop();
                count++;
            }

            if (i == n && minHeap.empty())
            {
                break;
            }
        }

        // Step 6: Return result
        return count;
    }
};