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
    bool check(vector<int>temp,int n){
        int i =0;
        int j = n-1;
        while(i<=j){
            if(temp[i]!=temp[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int>temp;
        ListNode* cur = head;
        while(cur){
            temp.push_back(cur->val);
            cur=cur->next;
        }
        int n = temp.size();
        return check(temp,n);
    }

};