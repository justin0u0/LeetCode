/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * Runtime: 24ms
 */

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (root == nullptr) {
      return vector<vector<int>>{};
    }

    queue<Node*> q;
    q.push(root);

    vector<vector<int>> answer;
    while (!q.empty()) {
      int size = q.size();
      vector<int> box;
      while (size--) {
        Node* u = q.front();
        q.pop();
        box.emplace_back(u->val);

        for (Node* v : u->children) {
          q.push(v);
        }
      }
      answer.emplace_back(box);
    }

    return answer;
  }
};
