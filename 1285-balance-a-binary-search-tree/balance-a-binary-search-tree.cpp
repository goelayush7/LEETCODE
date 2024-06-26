/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& inorderTrav) {
        if (root == nullptr) return;
        inorder(root->left, inorderTrav);
        inorderTrav.push_back(root);
        inorder(root->right, inorderTrav);
    }

    TreeNode* balancedBST(vector<TreeNode*>& ino, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = ino[mid];
        node->left = balancedBST(ino, start, mid - 1);
        node->right = balancedBST(ino, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> ino;
        inorder(root, ino);
        return balancedBST(ino, 0, ino.size() - 1);
    }
};