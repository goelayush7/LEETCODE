class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        multiset<vector<int>> st;  // Set to store rows
        multiset<vector<int>> st2; // Set to store columns

        // Insert rows into st
        for (int i = 0; i < grid.size(); i++) {
            st.insert(grid[i]);
        }
        int count =0;
        // Insert columns into st2
        for (int j = 0; j < grid.size(); j++) {
            vector<int> temp;
            for (int i = 0; i < grid.size(); i++) {
                temp.push_back(grid[i][j]);
            }
            count+=st.count(temp);
        }

        
        return count;
    }
};
