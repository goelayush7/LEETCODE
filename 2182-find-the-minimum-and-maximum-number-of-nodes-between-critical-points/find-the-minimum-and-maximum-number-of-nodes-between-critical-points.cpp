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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int index = 1;
        vector<int> criticalPoints;
        ListNode* temp = head;
        int prevval = temp->val;
        temp = temp->next;
        while (temp->next != nullptr) {
            if ((temp->val > prevval && temp->val > temp->next->val) ||
                (temp->val < prevval && temp->val < temp->next->val)) {
                criticalPoints.push_back(index);
            }
            prevval = temp->val;
            temp = temp->next;
            ++index;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int mini = INT_MAX;
        int maxi = criticalPoints.back() - criticalPoints.front();
        for (size_t i = 0; i < criticalPoints.size() - 1; ++i) {
            mini = min(criticalPoints[i + 1] - criticalPoints[i], mini);
        }

        return {mini, maxi};
    }
};
