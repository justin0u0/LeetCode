/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * Runtime: 16ms
 * Space Complexity: O(1)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }

    Node* cur = root;
    while (cur != nullptr) {
      // next level head & cursor
      Node* nhead = nullptr;
      Node* ncur = nullptr;
      for (; cur != nullptr; cur = cur->next) {
        if (cur->left != nullptr) {
          if (nhead == nullptr) {
            nhead = cur->left;
            ncur = nhead;
          } else {
            ncur->next = cur->left;
            ncur = ncur->next;
          }
        }
        if (cur->right != nullptr) {
          if (nhead == nullptr) {
            nhead = cur->right;
            ncur = nhead;
          } else {
            ncur->next = cur->right;
            ncur = ncur->next;
          }
        }
      }

      cur = nhead;
    }

    return root;
  }
};
