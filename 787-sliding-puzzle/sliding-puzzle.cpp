class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        string start = "";
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                start += to_string(board[i][j]);
            }
        }
        
        string target = "123450";
        
            unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};
        
        // BFS initialization
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(start);
        visited.insert(start);
        
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                string curr = q.front();
                q.pop();
                
                if (curr == target) {
                    return level;
                }
                
                int indexOfZero = curr.find('0');
                
                for (int swapIdx : mp[indexOfZero]) {
                    string newState = curr;
                    swap(newState[indexOfZero], newState[swapIdx]);
                    
                    if (visited.find(newState) == visited.end()) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};
