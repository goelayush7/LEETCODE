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
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while(temp!=NULL){
            int sum = 0;
            while(temp->val!=0){
                sum+=temp->val;
                temp = temp->next;
            }
            temp = temp->next;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
        }
        return ans->next;

    }
};