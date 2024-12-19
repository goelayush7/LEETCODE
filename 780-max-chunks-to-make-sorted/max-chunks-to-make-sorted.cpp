class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxelement = arr[0];
        int count =0;
        for(int i =0;i<arr.size();i++){
            maxelement = max(maxelement,arr[i]);
            if(maxelement==i)count++;
        }
        return count;
    }
};