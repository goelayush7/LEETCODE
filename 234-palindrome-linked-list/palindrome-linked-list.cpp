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
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int n =0;
        ListNode* temp = head;
        while(temp!=NULL){
             n++;

            temp = temp->next;
        }
        n = n/2;
        temp =head;
        while(n){
            temp=temp->next;
            n--;
        }
        ListNode* newnode = reverse(temp);
        while(newnode!=NULL && head!=NULL){
            if(newnode->val != head->val) return false;
            newnode = newnode->next;
            head = head->next;
        }
        return true;
    }
};