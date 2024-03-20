/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-in-between-linked-lists/
 * Runtime: 146ms (99.50%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* cur = list1;
    for (int i = 0; i < a - 1; ++i) {
      cur = cur->next;
    }
    ListNode* tmp = cur;
    for (int i = 0; i < b - a + 1; ++i) {
      cur = cur->next;
    }
    tmp->next = list2;
    
    ListNode* cur2 = list2;
    while (cur2->next != nullptr) {
      cur2 = cur2->next;
    }
    cur2->next = cur->next;

    return list1;
  }
};
