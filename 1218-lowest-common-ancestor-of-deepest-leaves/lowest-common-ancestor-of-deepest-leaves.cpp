/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> maps;
    int dmax = 0;
    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || maps[root->val] == dmax) {
            return root;
        }
        TreeNode* lca1 = LCA(root->left);
        TreeNode* lca2 = LCA(root->right);
        if (lca1 != NULL && lca2 != NULL) {
            return root;
        }
        if (lca1 != NULL)
            return lca1;
        return lca2;
    }
    void depth(TreeNode* root, int d) {
        if (root == NULL)
            return;
        maps[root->val] = d;
        dmax = max(dmax, d);
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return LCA(root);
    }
};