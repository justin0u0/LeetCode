/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reorder-list/
 * Runtime: 18ms (94.14%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode* prev = nullptr;
    while (slow != nullptr) {
      ListNode* n = slow->next;
      slow->next = prev;
      prev = slow;
      slow = n;
    }

    fast = head;
    while (fast != nullptr) {
      ListNode* n1 = fast->next;
      ListNode* n2 = prev->next;
      fast->next = prev;
      prev->next = n1;
      fast = n1;
      prev = n2;
    }
  }
};
