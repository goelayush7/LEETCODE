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
    int len(ListNode* head){
        int k = 0;
        ListNode* temp =head;
        while(temp!=NULL){
            k++;
            temp = temp->next;
        }
        return k;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 ||head->next==NULL) return head;
        int n = len(head);
        if(k>n)k=k%n;
        while(k){
            ListNode* tail = head;
            ListNode* prev = NULL;
            while(tail->next!=NULL){
            prev = tail;
            tail = tail->next;
            }
            tail->next = head;
            head = tail;
            prev->next = NULL;
            k--;
        }
        return head;
    }
};