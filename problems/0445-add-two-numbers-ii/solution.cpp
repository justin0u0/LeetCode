/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-two-numbers-ii/
 * Runtime: 32ms (85.32%)
 */

class Solution {
private:
  bool carry(ListNode* l) {
    if (l == nullptr) {
      return false;
    }

    l->val += carry(l->next);
    if (l->val > 9) {
      l->val -= 10;
      return true;
    }

    return false;
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = 0;
    int len2 = 0;
    for (ListNode* n = l1; n != nullptr; n = n->next) {
      ++len1;
    }
    for (ListNode* n = l2; n != nullptr; n = n->next) {
      ++len2;
    }

    if (len1 < len2) {
      swap(len1, len2);
      swap(l1, l2);
    }

    ListNode* n1 = l1;
    for (int i = 0; i < len1 - len2; ++i) {
      n1 = n1->next;
    }
    for (ListNode* n2 = l2; n2 != nullptr; n2 = n2->next) {
      n1->val += n2->val;
      n1 = n1->next;
    }

    if (carry(l1)) {
      ListNode* n = new ListNode(1);
      n->next = l1;
      return n;
    }
    return l1;
  }
};
