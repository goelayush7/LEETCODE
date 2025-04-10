class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                // Skip all duplicates
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                // Remove all of them
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }

        return dummy.next;
    }
};
