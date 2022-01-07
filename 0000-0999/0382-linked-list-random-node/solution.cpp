/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/linked-list-random-node/
 * Runtime: 52ms
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
  ListNode* head;
public:
  Solution(ListNode* head) {
    this->head = head;
  }

  int getRandom() {
    int len = 1;
    int val;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
      // probability of replacement
      // 1/1 -> 1/2 -> 1/3 -> 1/4 ....
      if (rand() % len == 0) {
        val = cur->val;
      }

      ++len;
    }
    
    return val;
  }
};
