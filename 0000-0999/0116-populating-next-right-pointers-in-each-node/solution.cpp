/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Runtime: 10ms (88.36%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();

      Node* prev = nullptr;
      while (sz--) {
        Node* u = q.front();
        q.pop();

        if (prev != nullptr) {
          prev->next = u;
        }
        prev = u;

        if (u->left != nullptr) {
          q.push(u->left);
          q.push(u->right);
        }
      }
    }

    return root;
  }
};
