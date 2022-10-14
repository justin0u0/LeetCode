/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 * Runtime: 1114ms (87.40%)
 */

class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
  }
};
