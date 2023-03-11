/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Runtime: 22ms (92.11%)
 */

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head, ListNode* end = nullptr) {
    if (head == end) {
      return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != end && fast->next != end) {
      fast = fast->next->next;
      slow = slow->next;
    }

    TreeNode* n = new TreeNode(slow->val);
    n->left = sortedListToBST(head, slow);
    n->right = sortedListToBST(slow->next, end);
    return n;
  }
};
