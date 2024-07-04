/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-nodes-in-between-zeros/
 * Runtime: 350ms (99.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* mergeNodes(ListNode* head) {
    int sum = 0;
    ListNode* n = head->next;
    for (ListNode* cur = head->next; cur != nullptr; cur = cur->next) {
      if (cur->val == 0) {
        n->val = sum;
        sum = 0;
        n->next = cur->next;
        n = cur->next;
      } else {
        sum += cur->val;
      }
    }
    return head->next;
  }
};
