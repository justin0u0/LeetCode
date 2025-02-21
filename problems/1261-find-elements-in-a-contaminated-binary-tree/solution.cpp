/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
 * Runtime: 5ms (86.92%)
 */

class FindElements {
private:
  unordered_set<int> s;
public:
  FindElements(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto [n, o] = q.front();
      s.emplace(o);
      q.pop();
      if (n->left != nullptr) {
        q.push({n->left, (o << 1) + 1});
      }
      if (n->right != nullptr) {
        q.push({n->right, (o << 1) + 2});
      }
    }
  }
  
  bool find(int target) {
    return s.find(target) != s.end();
  }
};
