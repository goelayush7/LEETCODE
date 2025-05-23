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
        ListNode* temp = head->next;
        int value = 0;
        ListNode* ans = new ListNode(0);
        ListNode* temp1 = ans;
        while(temp!=NULL){
            value+=temp->val;
            if(temp->val==0){
                if(value!=0){
                    ListNode* newnode = new ListNode(value);
                    value = 0;
                    ans->next = newnode;
                    ans = ans->next;
                }
            }
            temp = temp->next;
        }
        return temp1->next;
    }
};