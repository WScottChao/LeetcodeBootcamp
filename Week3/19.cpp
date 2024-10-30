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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 2: Move first n + 1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Step 3: Move first and second together until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Step 4: Delete the target node
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        // Step 5: Return the new head and clean up
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
        }
};
