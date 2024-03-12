/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
 * Runtime: 3ms (97.32%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);

    unordered_map<int, ListNode*> m;
    m.emplace(0, dummy);
    int sum = 0;
    ListNode* prev = dummy;

    for (ListNode* u = head; u != nullptr; u = u->next) {
      sum += u->val;
      if (m.find(sum) != m.end()) {
        ListNode* n = m.at(sum);
        int s = sum;
        for (ListNode* v = n->next; v != u; v = v->next) {
          s += v->val;
          m.erase(s);
        }
        n->next = u->next;
        prev = n;
      } else {
        m.emplace(sum, u);
        prev = u;
      }
    }
    return dummy->next;
  }
};
