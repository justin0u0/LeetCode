/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/odd-even-linked-list/
 * Runtime: 12ms (89.66%)
 */

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode* dummy1 = new ListNode;
    ListNode* dummy2 = new ListNode;
    ListNode* l1 = dummy1;
    ListNode* l2 = dummy2;
    bool turn = true;
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
      if (turn) {
        l1->next = cur;
        l1 = l1->next;
      } else {
        l2->next = cur;
        l2 = l2->next;
      }
      turn ^= 1;
    }

    l1->next = dummy2->next;
    l2->next = nullptr;
    return dummy1->next;
  }
};
