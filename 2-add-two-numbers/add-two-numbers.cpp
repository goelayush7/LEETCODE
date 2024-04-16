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
        int carry = 0;
        int sum = 0;
        ListNode* head = new ListNode(0) ;
        ListNode* temp = head;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val1=0;
            if(l1){
                val1 = l1->val;
                l1=l1->next;
            }
            int val2=0;
            if(l2){
                val2 = l2->val;
                l2=l2->next;
            }
            sum = val1+val2+carry;
            carry = sum/10;
            ListNode* newhead = new ListNode(sum%10);
            head->next = newhead;
            head=head->next;
        }
        return temp->next;
    }
};