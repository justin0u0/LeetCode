/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-two-numbers/
 * Runtime: 60ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode;
    ListNode* dummyHead = dummy;

    int carry = 0;
    while (l1 != nullptr && l2 != nullptr) {
      int sum = l1->val + l2->val + carry;
      dummy->next = new ListNode(sum % 10);
      carry = sum / 10;

      l1 = l1->next;
      l2 = l2->next;
      dummy = dummy->next;
    }

    if (l1 == nullptr) {
      swap(l1, l2);
    }

    while (l1 != nullptr) {
      int sum = l1->val + carry;
      dummy->next = new ListNode(sum % 10);
      carry = sum / 10;

      l1 = l1->next;
      dummy = dummy->next;
    }

    if (carry != 0) {
      dummy->next = new ListNode(carry);
    }

    return dummyHead->next;
  }
};
