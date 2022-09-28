/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Runtime: 0ms
 */

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }

    ListNode* slow = dummy;
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
  }
};
