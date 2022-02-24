/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-list/
 * Runtime: 124ms
 * Time Complexity: O(N)
 * Space Complexity: O(1)
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
private:
  ListNode* splitList(ListNode* head, int n) {
    ListNode* cur = head;
    for (int i = 0; i < n / 2 - 1; ++i) {
      cur = cur->next;
    }

    ListNode* mid = cur->next;
    cur->next = nullptr;

    return mid;
  }

  ListNode* mergeSort(ListNode* head, int n) {
    if (n <= 1) {
      return head;
    }

    ListNode* mid = splitList(head, n);
    ListNode* l = mergeSort(head, n / 2);
    ListNode* r = mergeSort(mid, n - n / 2);

    ListNode* dummy = new ListNode;
    ListNode* dummyHead = dummy;
    while (l != nullptr || r != nullptr) {
      if (r == nullptr || (l != nullptr && l->val < r->val)) {
        dummy->next = l;
        l = l->next;
      } else {
        dummy->next = r;
        r = r->next;
      }

      dummy = dummy->next;
    }
 
    return dummyHead->next;
  }
public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* cur = head;
    int n = 0;
    while (cur != nullptr) {
      cur = cur->next;
      ++n;
    }

    return mergeSort(head, n);
  }
};
