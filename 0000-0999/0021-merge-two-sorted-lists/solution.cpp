/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-two-sorted-lists/
 * Runtime: 4ms
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode;
    ListNode* dummyHead = dummy;
    while (list1 != nullptr || list2 != nullptr) {
      if (list2 == nullptr || (list1 != nullptr && list1->val < list2->val)) {
        dummy->next = list1;
        list1 = list1->next;
      } else {
        dummy->next = list2;
        list2 = list2->next;
      }

      dummy = dummy->next;
    }

    return dummyHead->next;
  }
};
