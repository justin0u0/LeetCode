/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * Runtime: 16ms
 * Space Complexity: O(N)
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

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = (int)q.size();

      Node* cur = q.front();
      q.pop();

      if (cur->left != nullptr) {
        q.push(cur->left);
      }
      if (cur->right != nullptr) {
        q.push(cur->right);
      }

      while (--sz) {
        cur->next = q.front();
        q.pop();
        cur = cur->next;

        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
      }
    }

    return root;
  }
};
