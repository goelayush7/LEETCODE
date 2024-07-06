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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1 = new ListNode(0);
        ListNode* newhead = head1;
        if (head->next == NULL)
            return NULL;
        ListNode* temp = head->next;
        int value = 0;
        while (temp->next != 0) {
            if (temp->val != 0) {
                value += temp->val;
            }
            temp = temp->next;
            if (temp->val == 0) {
                head1->next = new ListNode(value);
                head1 = head1->next;
                value = 0;
            }
        }
        return newhead->next;
    }
};