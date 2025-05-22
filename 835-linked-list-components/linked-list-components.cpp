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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int count =1;
        bool isconnected = true;
        if(st.find(head->val)==st.end()){
            isconnected = false;
            count = 0;
        }
        while(head!=NULL){
            int value = head->val;
            head = head->next;
            if(isconnected && st.find(value)!=st.end()){
                continue;
            }
            else if(st.find(value)==st.end()){
                isconnected = false;
            }
            else{
                count = count+1;
                isconnected = true;
            }
        }
        return count;
        
    }
};