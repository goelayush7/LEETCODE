class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    // Floor: greatest value ≤ target
    int findFloor(const vector<int>& vals, int target) {
        int start = 0, end = vals.size() - 1;
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (vals[mid] <= target) {
                res = vals[mid];
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }

    // Ceiling: smallest value ≥ target
    int findCeiling(const vector<int>& vals, int target) {
        int start = 0, end = vals.size() - 1;
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (vals[mid] >= target) {
                res = vals[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedVals;
        inorder(root, sortedVals);
        vector<vector<int>> result;
        for (int q : queries) {
            int floor = findFloor(sortedVals, q);
            int ceiling = findCeiling(sortedVals, q);
            result.push_back({floor, ceiling});
        }
        return result;
    }
};
