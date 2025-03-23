class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

    void unionSets(int x, int y, vector<int>& size, vector<int>& parent) {
        int parentX = findParent(x, parent);
        int parentY = findParent(y, parent);
        
        if (parentX == parentY) return;
        
        if (size[parentX] > size[parentY]) {
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        } else {
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n), size(n, 1);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Connect stones in the same row or column using union
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unionSets(i, j, size, parent);
                }
            }
        }
        
        // Count connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) components++;
        }
        
        return n - components;
    }
};
