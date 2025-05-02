class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long> temp;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            temp.push_back(sum);
        }

        long long maxi = LLONG_MIN;
        int ans = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > maxi) {
                maxi = temp[i];
                ans = i + 1;  // levels are 1-indexed
            }
        }
        return ans;
    }
};
