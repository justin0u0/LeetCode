/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* prev = head;
    for (ListNode* cur = head->next; cur != nullptr; cur = cur->next) {
      if (cur->val == prev->val) {
        prev->next = cur->next;
      } else {
        prev = cur;
      }
    }
    return head;
  }
};
