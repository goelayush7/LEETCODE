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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode* cpy = head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            if(prev->val==cur->val){
                prev->next = temp;
                cur = temp;
            }
            else{
                cur = cur->next;
                prev =prev->next;
            }
        }
        return cpy;
    }
};