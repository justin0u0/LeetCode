/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-nodes-from-linked-list/
 * Runtime: 185ms (99.95%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* removeNodes(ListNode* head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur != nullptr) {
      ListNode* nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    int val = 0;
    cur = pre;
    pre = nullptr;
    while (cur != nullptr) {
      ListNode* nxt = cur->next;
      if (cur->val >= val) {
        val = cur->val;
        cur->next = pre;
        pre = cur;
      }
      cur = nxt;
    }
    return pre;
  }
};
