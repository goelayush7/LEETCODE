class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;
        int carry = 0;

        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            temp->next = new ListNode(val % 10);
            carry = val / 10;

            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int val = l1->val + carry;
            temp->next = new ListNode(val % 10);
            carry = val / 10;

            temp = temp->next;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            int val = l2->val + carry;
            temp->next = new ListNode(val % 10);
            carry = val / 10;

            temp = temp->next;
            l2 = l2->next;
        }

        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
