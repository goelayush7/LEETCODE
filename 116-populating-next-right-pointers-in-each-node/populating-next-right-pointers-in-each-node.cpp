/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        Node* ans = root;
        while (!q.empty()) {
            int n = q.size();
            vector<Node*> vect;
            for (int i = 0; i <n; i++) {
                Node* n = q.front();
                q.pop();
                vect.push_back(n);
                if (n->left != NULL)
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);
            }
            for (int i = 0; i < vect.size() - 1; i++) {
                Node* n = vect[i];
                Node* n1 = vect[i + 1];
                n->next = n1;
            }
            vect[vect.size() - 1]->next = NULL;
        }
        return ans;
    }
};