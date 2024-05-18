class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);  // Correctly initialize the level vector with size n
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine the index based on the current flag
                int index = flag ? n - 1 - i : i;
                level[index] = node->val;

                // Push left and right children into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
            flag = !flag;  // Toggle the flag
        }

        return ans;
    }
};