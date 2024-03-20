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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start =  list1;
        ListNode* end  = list1;
        int n = 0;
        ListNode* tail = list2;
        ListNode* temp = list2;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        
        while(n!=a-1){
            start = start->next;
            end = end->next;
            n++;
        }
        while(n!=b){
            end = end->next;
            n++;
        }
        start->next = list2;
        tail->next = end->next;
        return list1;
    }
};