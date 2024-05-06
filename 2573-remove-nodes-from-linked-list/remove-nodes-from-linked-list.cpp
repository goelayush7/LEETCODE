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
    ListNode* removeNodes(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while (temp != nullptr) {
            while (!s.empty() && s.top() < temp->val) {
                s.pop();
            }
            s.push(temp->val);
            temp = temp->next;
        }

        ListNode* finalHead = nullptr;
        while (!s.empty()) {
            ListNode* newNode = new ListNode(s.top());
            newNode->next = finalHead;
            finalHead = newNode;
            s.pop();
        }

        return finalHead;
    }
};
