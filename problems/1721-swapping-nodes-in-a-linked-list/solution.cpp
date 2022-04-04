/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * Runtime: 941ms
 */

class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* cur = head;
    for (int i = 0; i < k - 1; ++i) {
      cur = cur->next;
    }

    ListNode* t1 = cur;
    ListNode* t2 = head;
    while (cur->next != nullptr) {
      cur = cur->next;
      t2 = t2->next;
    }

    swap(t1->val, t2->val);

    return head;
  }
};
