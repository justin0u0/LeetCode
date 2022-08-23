/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-linked-list/
 * Runtime: 267ms
 */

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    int checks = 0;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      ++checks;
    }

    ListNode* pre = nullptr;
    while (slow != nullptr) {
      ListNode* temp = slow->next;
      slow->next = pre;
      pre = slow;
      slow = temp;
    }

    ListNode* l = head;
    ListNode* r = pre;
    while (checks--) {
      if (l->val != r->val) {
        return false;
      }
      l = l->next;
      r = r->next;
    }

    return true;
  }
};

