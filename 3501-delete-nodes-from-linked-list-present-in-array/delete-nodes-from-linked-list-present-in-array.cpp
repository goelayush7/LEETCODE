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
        unordered_map<int,int>maps;
        for(auto it : nums){
            maps[it]++;
        }
        while(head->next!=nullptr && maps.find(head->val)!=maps.end()){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* cur =head;
        ListNode* prev = NULL;
        while(cur!=NULL){
            if(maps.find(cur->val)!=maps.end()){
                prev->next = cur->next;
                cur = cur->next;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};