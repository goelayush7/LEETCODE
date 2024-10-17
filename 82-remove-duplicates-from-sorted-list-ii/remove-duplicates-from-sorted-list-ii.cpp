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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>maps;
        ListNode* temp = head;
        while(temp!=NULL){
            int value = temp->val;
            maps[value]++;
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        vector<int>t;
        ListNode* cpy =ans;
        for(auto it : maps){
            if(it.second==1){
                t.push_back(it.first);
            }
        }
        sort(t.begin(),t.end());
        for(auto it : t){
            ListNode* node = new ListNode(it);
            ans->next = node;
            ans = ans->next;
        }
        return cpy->next;

    }
};