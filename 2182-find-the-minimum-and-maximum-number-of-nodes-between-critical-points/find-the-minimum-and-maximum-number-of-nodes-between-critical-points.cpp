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
        vector<int> result(2, -1); // Initialize result with [-1, -1]

        if (!head || !head->next || !head->next->next) {
            return result; // Less than 3 nodes, no critical points possible
        }

        int firstPos = -1, lastPos = -1, minDistance = INT_MAX;
        int pos = 1; // Current position
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (firstPos == -1) {
                    firstPos = pos;
                } else {
                    minDistance = min(minDistance, pos - lastPos);
                }
                lastPos = pos;
            }

            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }

        if (firstPos == lastPos || firstPos == -1) {
            return result; // Fewer than two critical points
        }

        result[0] = minDistance;
        result[1] = lastPos - firstPos;

        return result;
    }
};
