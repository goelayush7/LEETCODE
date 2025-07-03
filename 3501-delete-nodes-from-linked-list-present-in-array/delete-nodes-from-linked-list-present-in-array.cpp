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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* dummy = prev;
        ListNode* temp = head;
        while(temp){
            if(st.find(temp->val)!=NULL){
                prev->next = temp->next;
            }
            else prev = prev->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};