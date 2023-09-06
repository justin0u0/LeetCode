/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/split-linked-list-in-parts/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
      ++len;
    }
    vector<ListNode*> answer(k, nullptr);
    ListNode* cur = head;
    for (int i = 0; i < k; ++i) {
      answer[i] = cur;
      for (int j = 0; j < len / k - (i >= len % k); ++j) {
        cur = cur->next;
      }
      if (cur == nullptr) {
        break;
      }
      auto n = cur->next;
      cur->next = nullptr;
      cur = n;
    }
    return answer;
  }
}
