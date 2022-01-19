/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/linked-list-cycle-ii/
 * Runtime: 8ms
 * Description:
 * `slow` move 1 step and `fast` move 2 steps every time.
 *
 * When they meet, `slow` goes x+y steps and `fast` goes 2(x+y) steps,
 * where x is the distance to the entrypoint and y is the distance from
 * the entrypoint to the meet point. Since they met, we know that 2(x+y)
 * -(x+y) = (x+y) is the multiple of C, where C is the cycle length.
 *
 * So let (x+y) = NC -> x = NC - y.
 * Then when `slow` keep moving for x steps, which is x+y+x = x+y+(NC-y)
 * = x+NC steps. It returns to the entrypoint.
 *
 * So if after `slow` and `fast` meet, `head` move 1 step and `slow` move
 * 1 step every time. They will meet at the entrypoint.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    do {
      slow = slow->next;
      fast = fast->next;
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;
      if (fast == nullptr) {
        return nullptr;
      }
    } while (slow != fast);

    while (head != slow) {
      head = head->next;
      slow = slow->next;
    }

    return head;
  }
};
