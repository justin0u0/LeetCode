/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-linked-list/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
}
