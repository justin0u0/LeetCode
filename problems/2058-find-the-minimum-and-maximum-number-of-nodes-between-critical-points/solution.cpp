/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 * Runtime: 100ms (99.85%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = head;
    int first = -1;
    int last = -1;
    int d = INT_MAX;
    int i = 0;
    for (ListNode* cur = head->next; cur->next != nullptr; cur = cur->next) {
      if ((prev->val < cur->val && cur->next->val < cur->val)
        || (prev->val > cur->val && cur->next->val > cur->val)) {
        if (first == -1) {
          first = i;
          last = i;
        } else {
          d = min(d, i - last);
          last = i;
        }
      }
      prev = cur;
      ++i;
    }
    if (d == INT_MAX) {
      return {-1, -1};
    }
    return {d, last - first};
  }
};
