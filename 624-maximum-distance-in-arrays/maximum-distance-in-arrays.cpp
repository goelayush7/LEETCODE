// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
//         vector<pair<int,int>>mini;
//         vector<pair<int,int>>maxi;
//         int n = arrays.size();
//         for(int i =0;i<n;i++){
//             int n1 = arrays[i].size();
//             mini.push_back({arrays[i][0],i});
//             maxi.push_back({arrays[i][n1-1],i});
//         }
//         int ans = INT_MIN;
//         for(int i =0;i<n;i++){
//             for(int j =0;j<n;j++){
//                 if(mini[j].second!=maxi[i].second){
//                 ans = max(abs(mini[j].first-maxi[i].first),ans);
//             }
//             }
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};