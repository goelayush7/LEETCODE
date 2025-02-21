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
class FindElements {
public:
    unordered_map<int,int>maps;
    FindElements(TreeNode* root) {
        helper(root,0);
    }
    void helper(TreeNode* root,int val){
        maps[val]++;
        root->val = val;
        if(root->left){
            helper(root->left,(2*root->val)+1);
        }
        if(root->right){
            helper(root->right,(2*root->val)+2);
        }
    }
    bool find(int target) {
        if(maps.find(target)==maps.end())return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */