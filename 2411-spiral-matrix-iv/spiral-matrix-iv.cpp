/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int sr = 0;
        int sc = 0;
        int ec = n - 1;
        int er = m - 1;
        while (sc <= ec && sr <= er && head != NULL) {
            for (int i = sc; i <= ec && head != NULL; i++) {
                mat[sr][i] = head->val;
                head = head->next;
            }
            sr++;
            for (int i = sr; i <= er && head != NULL; i++) {
                mat[i][ec] = head->val;
                head = head->next;
            }
            ec--;
            if (sr <= er && head != NULL) {
                for (int i = ec; i >= sc && head != NULL; i--) {
                    mat[er][i] = head->val;
                    head = head->next;
                }
                er--;
            }
            if (sc <= ec && head != NULL) {
                for (int i = er; i >= sr && head!=NULL; i--) {
                    mat[i][sc] = head->val;
                    head = head->next;
                }
                sc++;
            }
        }
        return mat;
    }
};