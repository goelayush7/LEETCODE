class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_map, y_map;
        
        // Create events for x and y coordinates
        for (int i = 0; i < rectangles.size(); i++) {
            int startx = rectangles[i][0];
            int starty = rectangles[i][1];
            int endx = rectangles[i][2];
            int endy = rectangles[i][3];
            
            x_map.push_back({startx, 1}); // Start of rectangle in x
            x_map.push_back({endx, 0});   // End of rectangle in x
            
            y_map.push_back({starty, 1}); // Start of rectangle in y
            y_map.push_back({endy, 0});   // End of rectangle in y
        }
        
        sort(x_map.begin(), x_map.end());
        sort(y_map.begin(), y_map.end());
        
        // Check horizontal cuts
        int count = 0;
        int horizontal_cuts = 0;
        for (auto& it : x_map) {
            if (it.second == 0) {
                count--;
            } else {
                count++;
            }
            if (count == 0) {
                horizontal_cuts++;
            }
        }
        
        // Check vertical cuts
        count = 0;
        int vertical_cuts = 0;
        for (auto& it : y_map) {
            if (it.second == 0) {
                count--;
            } else {
                count++;
            }
            if (count == 0) {
                vertical_cuts++;
            }
        }
        cout<<horizontal_cuts<<endl;
        cout<<vertical_cuts<<endl;

        
        // Check if at least 2 horizontal or 2 vertical cuts are possible
        return horizontal_cuts >= 3 || vertical_cuts >= 3;
    }
};
