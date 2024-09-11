/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
 * Runtime: 33ms (84.82%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    for (ListNode* cur = head; cur->next != nullptr; cur = cur->next) {
      ListNode* n = new ListNode(__gcd(cur->val, cur->next->val), cur->next);
      cur->next = n;
      cur = n;
    }
    return head;
  }
};
