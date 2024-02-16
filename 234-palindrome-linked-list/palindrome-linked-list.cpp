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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev= cur;
            cur= temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* temp =head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        temp = head;
        n = n/2;
        while(n){
            temp = temp->next;
            n--;
        }
        ListNode* newhead= reverse(temp);
        temp->next = NULL;
        while(newhead!=NULL && head!=NULL){
            if(newhead->val != head->val) return false;
            newhead = newhead->next;
            head = head->next;
        }
        return true;
    }
};