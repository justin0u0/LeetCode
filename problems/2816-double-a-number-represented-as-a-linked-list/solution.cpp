/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
 * Runtime: 147ms (98.40%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* doubleIt(ListNode* head) {
    function<int(ListNode* cur)> dfs = [&](ListNode* cur) {
      if (cur == nullptr) {
        return 0;
      }
      int carry = dfs(cur->next);

      cur->val <<= 1;
      if (carry != 0) {
        ++cur->val;
      }
      if (cur->val > 9) {
        cur->val -= 10;
        return 1;
      }
      return 0;
    };
    if (dfs(head) != 0) {
      return new ListNode(1, head);
    }
    return head;
  }
};
