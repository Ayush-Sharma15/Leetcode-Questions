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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int sum = 0;
        
        // Skip the initial zero
        head = head->next;
        
        while (head != nullptr) {
            if (head->val == 0) {
                // Create a new node with the sum and attach to the result list
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0;
            } else {
                // Accumulate the sum
                sum += head->val;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
