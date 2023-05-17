/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 * Runtime: 224ms (98.87%)
 */

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }

    int answer = 0;
    while (slow) {
      answer = max(answer, slow->val + prev->val);
      slow = slow->next;
      prev = prev->next;
    }
    return answer;
  }
};
