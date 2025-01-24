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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)return NULL;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        n = size-n;
        temp = head;
        ListNode* prev = NULL;
        while(n--){
            prev = temp;
            temp = temp->next;
        }
        if(prev==NULL)return temp->next;
        if(temp->next)prev->next=temp->next;
        else prev->next = NULL;
        return head;
    }
};