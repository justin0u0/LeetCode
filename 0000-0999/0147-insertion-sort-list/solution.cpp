/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/insertion-sort-list/
 * Runtime: 29ms (53.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode* sorted = new ListNode(INT_MIN);

    ListNode* next;
    for (ListNode* i = head; i != nullptr; i = next) {
      next = i->next;

      ListNode* j = sorted;
      while (j->next != nullptr && i->val > j->next->val) {
        j = j->next;
      }
      ListNode* tmp = j->next;
      j->next = i;
      i->next = tmp;
    }

    return sorted->next;
  }
};
