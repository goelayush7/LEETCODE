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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        int n =0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        n = n/2;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(n--){
            prev = cur;
            cur = cur->next;
        }
        prev ->next = cur->next;
        delete cur;
        return head;

    }
};