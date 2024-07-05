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
        vector<int> result(2, -1);  // Initialize result with [-1, -1]

        if (!head || !head->next || !head->next->next) {
            return result;  // Less than 3 nodes, no critical points possible
        }

        vector<int> criticalPoints;  // Store positions of critical points
        ListNode* slow = head;
        ListNode* current = head->next;
        ListNode* fast = head->next->next;
        int position = 1;  // Current node position in the list

        while (fast) {
            if ((current->val > slow->val && current->val > fast->val) ||
                (current->val < slow->val && current->val < fast->val)) {
                criticalPoints.push_back(position);
            }
            slow = current;
            current = fast;
            fast = fast->next;
            position++;
        }

        if (criticalPoints.size() < 2) {
            return result;  // Fewer than 2 critical points
        }

        int minDistance = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        result[0] = minDistance;
        result[1] = maxDistance;

        return result;
    }
};
