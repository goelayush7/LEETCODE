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
    int greatestdivisor(ListNode* head1,ListNode* head2){
        int val1 = head1->val;
        int val2 = head2->val;
        int cur = 0;
        for(int i =1;i<=min(val1,val2);i++){
            if(val1%i==0 && val2%i==0){
                cur = max(cur,i);
            }
        }
        return cur;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur->next!=NULL){
            int div = greatestdivisor(cur,cur->next);
            cout<<div;
            ListNode* temp = new ListNode(div);
            ListNode* temp1 = cur->next;
            cur->next = temp;
            temp->next = temp1;
            prev = cur->next;
            cur = cur->next->next;
        }
        return head;

    }
};