/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int val = 0;
    while (head != nullptr) {
      val = (val << 1) | head->val;
      head = head->next;
    }
    return val;
  }
};
