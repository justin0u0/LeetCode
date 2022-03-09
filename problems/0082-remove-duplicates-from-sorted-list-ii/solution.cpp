/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Runtime: 8ms
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode;
    ListNode* dummyHead = dummy;

    int skip = -101;
    while (head != nullptr) {
      if (head->val != skip && (head->next == nullptr || head->val != head->next->val)) {
        dummy->next = head;
        dummy = dummy->next;
      } else {
        skip = head->val;
      }

      head = head->next;
    }

    dummy->next = nullptr;
    return dummyHead->next;
  }
};
