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
    bool isPalindrome(ListNode* head) {
        vector<int>vect;
        ListNode* temp = head;
        while(temp){
            vect.push_back(temp->val);
            temp = temp->next;
        }
        int i =0;
        int j =vect.size()-1;
        while(i<j){
            if(vect[i]!=vect[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};