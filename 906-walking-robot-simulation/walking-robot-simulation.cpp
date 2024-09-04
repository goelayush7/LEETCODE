class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(const auto &it : obstacles){
            st.insert({it[0],it[1]});
        }
        int x = 0;
        int y = 0;
        int north = 1;
        int south = 0;
        int west = 0;
        int east = 0;
        int ans =0;
        int maxi =0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                if (north == 1) {
                    north = 0;
                    east = 1;
                } else if (east == 1) {
                    east = 0;
                    south = 1;
                } else if (south == 1) {
                    south = 0;
                    west = 1;
                } else if (west == 1) {
                    west = 0;
                    north = 1;
                }
            }
            if (commands[i] == -2) {
                if (north == 1) {
                    north = 0;
                    west = 1;
                } else if (east == 1) {
                    east = 0;
                    north = 1;
                } else if (south == 1) {
                    south = 0;
                    east = 1;
                } else if (west == 1) {
                    west = 0;
                    south = 1;
                }
            }
            for (int j = 0; j < commands[i]; j++) {
                if (north == 1) {
                    if (st.find({x,y+1}) != st.end()) {
                        break;
                    }
                    y++;
                } else if (south == 1) {
                    if (st.find({x,y-1}) != st.end()) {
                        break;
                    } 
                    y--;

                } else if (east == 1) {
                    if (st.find({x+1,y}) != st.end()) {
                        break;
                    }
                    x++;

                } else if (west == 1) {
                    if (st.find({x-1,y}) != st.end()) {
                        break;
                    }
                    x--;
                }
                ans = x*x + y*y;
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
};