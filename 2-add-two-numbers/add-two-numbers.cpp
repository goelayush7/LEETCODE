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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;
        int carry = 0;
        while (l1 && l2) {
            int value = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            value += carry;
            carry = value / 10;
            value = value % 10;
            dummy->next = new ListNode(value);
            dummy = dummy->next;
        }
        while (l1) {
            int value = l1->val + carry;
            l1 = l1->next;
            carry = value / 10;
            value = value % 10;
            dummy->next = new ListNode(value);
            dummy = dummy->next;
        }
        while (l2) {
            int value = l2->val + carry;
            l2 = l2->next;
            carry = value / 10;
            value = value % 10;
            dummy->next = new ListNode(value);
            dummy = dummy->next;
        }
        if(carry>0)dummy->next = new ListNode(carry);
        return temp->next;
    }
};