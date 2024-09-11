/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
 * Runtime: 353ms (95.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s;
    for (int num : nums) {
      s.emplace(num);
    }
    
    ListNode* dummy = new ListNode(0, head);
    ListNode* pre = dummy;
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
      if (s.find(cur->val) != s.end()) {
        pre->next = cur->next;
      } else {
        pre = cur;
      }
    }
    return dummy->next;
  }
};
